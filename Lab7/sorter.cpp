#include <iostream> 
#include <vector>
#include <cmath>
#include <numeric> 

using namespace std;

bool check(vector<int>& a,vector<int>& b){
    int sa = accumulate(a.begin(),a.end(),0);
    int sb = accumulate(b.begin(),b.end(),0);
    if(sa > sb){
        return true;
    }
    else if(sa == sb){
        for(int i = 0; i<a.size(); i++){
            if(a[i]<b[i]){
                return true;
            }
            if(a[i]>b[i]){
                return false;
            }
        }
    }
    return false;
}

void merge(vector<vector<int>>& a, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<vector<int>> L(n1), R(n2);

    for(int i = 0; i<n1; i++){
        L[i] = a[l+i];
    }
    for(int i = 0; i<n2; i++){
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
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<vector<int>>& a, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);

        merge(a,l,r,mid);
    }
}

int main(){
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int val;
            cin >> val;
            a[i].push_back(val);
        }
    }
    mergesort(a,0,a.size()-1);
    for(auto& it:a){
        for(auto& it2: it){
            cout << it2 << ' ';
        }
        cout << endl;
    }
}