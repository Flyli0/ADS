#include <iostream> 
#include <vector>
#include <iomanip>

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

int partition(vector<pair<string,pair<string,double>>>& a, int low, int high){
    pair<string,pair<string,double>> pivot = a[high];
    int i = low - 1;

    for(int j = low; j<high; ++j){
        if(check(a[j],pivot)){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[high],a[i+1]);
    return i+1;
}

void quicksort(vector<pair<string,pair<string,double>>>& a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);

        quicksort(a, low , pivot-1);
        quicksort(a, pivot+1, high);
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
    quicksort(a,0,a.size()-1);
    for(const auto & it : a){
        cout << it.first << ' ' << it.second.first << ' ' << fixed << setprecision(3) << it.second.second << endl;
    }
}