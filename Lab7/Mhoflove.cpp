#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

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
        if(L[i]<=R[j]){
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

    while(j<n2){
        a[k] = R[j];
        k++;
        j++;
    }
}

void mergesort(vector<int>& a, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;

        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,r,mid);
    }
}

int main(){
    int n,m,val;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    vector<int> match;
    for(int i = 0; i<n; i++){
        cin >> val;
        a.push_back(val);
    }
    for(int i = 0; i<m; i++){
        cin >> val;
        b.push_back(val);
    }
    mergesort(a,0,a.size()-1);
    mergesort(b,0,b.size()-1);

    while(!a.size()==0 &&  !b.size()==0){
        if(a.back()>b.back()){
            a.pop_back();
        }
        if(b.back()>a.back()){
            b.pop_back();
        }
        if(a.back()==b.back()){
            match.push_back(a.back());
            a.pop_back();
            b.pop_back();
        }
    }
    
    for(int i = match.size()-1; i>=0; i--){
        cout << match[i] << ' ';
    }
}