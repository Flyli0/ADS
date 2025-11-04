#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool check(pair<string,pair<string,double>> a, pair<string,pair<string,double>> pivot){
    if(a.second.second < pivot.second.second){
        return true;
    }
    else if(a.second.second == pivot.second.second && a.first < pivot.first){
        return true;
    }
    else if(a.second.second == pivot.second.second && a.first == pivot.first && a.second.first <= pivot.second.first){
        return true;
    }
    return false;
}

void merge(vector<pair<string,pair<string,double>>>& a, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<pair<string,pair<string,double>>> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = a[i+l];
    }
    for(int i = 0; i < n2; i++){
        R[i] = a[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(check(L[i],R[j])){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;     
        }
        k++;
    }
    while(i<n1){
        a[k] = L[i];
        k++;
        i++;
    }
    while(j>n2){
        a[k] = R[i];
        k++;
        j++;
    }
}

void mergesort(vector<pair<string,pair<string,double>>>& a, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        mergesort(a,l,mid);
        mergesort(a,mid+1,r);

        merge(a, l, r, mid);
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<string,pair<string,double>>> a;
    for(int i = 0; i<n; i++){
        string name, surname, mark;
        int num,credits,csum = 0;
        double oldgpa,newgpa = 0;
        cin >> surname >> name;
        cin >> num;
        for(int j = 0; j<num; j++){
            cin >> mark >> credits;
            if(mark == "A+"){
                oldgpa = 4.00;
            }
            else if(mark == "A"){
                oldgpa = 3.75;
            }
            else if(mark == "B+"){
                oldgpa = 3.50;
            }
            else if(mark == "B"){
                oldgpa = 3.00;
            }
            else if(mark == "C+"){
                oldgpa = 2.50;
            }
            else if(mark == "C"){
                oldgpa = 2.00;
            }
            else if(mark == "D+"){
                oldgpa = 1.50;
            }
            else if(mark == "D"){
                oldgpa = 1.00;
            }
            else if(mark == "F"){
                oldgpa = 0.00;
            }
            newgpa+= credits * oldgpa;
            csum += credits;
        }
        newgpa /= csum;
        a.push_back({surname,{name,newgpa}});
    }
    mergesort(a,0,a.size()-1);
    for(const auto & it : a){
        cout << it.first << ' ' << it.second.first << ' ' << fixed << setprecision(3) << it.second.second << endl;
    }
}