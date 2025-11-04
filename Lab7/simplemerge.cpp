#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void merge(vector<string>& a, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<string> L(n1), R(n2);

    for(int i = 0; i<n1; i++){
        L[i] = a[l+i];
    }
    for(int i = 0; i<n2; i++){
        R[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(L[i].length()<=R[j].length()){
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
        i++;
        k++;
    }

    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<string>& a, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        mergesort(a,l,mid);
        mergesort(a,mid+1,r);

        merge(a,l,r,mid);
    }

}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    int j = 0;
    string line;
    string answer = "";
    for(int i = 0; i<n; i++){
        vector<string> a;
        string word;
        getline(cin,line);
        stringstream ss(line);

        while(ss>>word){
            a.push_back(word);
        }

        mergesort(a,0,a.size()-1);

        for (const string& w :a) {
            answer += w + " ";
        }
        
        answer += '\n';
        }
    cout << answer;
}