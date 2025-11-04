#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int l, int r, int mid){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1),R(n2);

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
        if(L[i] <= R[j]){
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
        int mid = l + (r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,r,mid);
    }
}

int main(){
    vector<int> a = {4,3,2,5,1};
    mergesort(a,0,a.size()-1);
    for(const auto& it:a){
        cout << it << ' ';
    }
}