#include <iostream>
#include <vector> 

using namespace std; 

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j<high; ++j){
        if(a[j]>=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(vector<int>& a, int low , int high){
    if(low < high){
        int pivot = partition(a,low,high);

        quicksort(a,low, pivot - 1);
        quicksort(a,pivot + 1, high);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> c;
    int b[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            b[i][j] = val;
        }
    }
    for(int j = 0; j < m; j++){
        vector<int> a;
        for(int i = 0; i<n; i++){
        a.push_back(b[i][j]);
        }
        quicksort(a,0,a.size()-1);
        for(int k = 0; k<a.size();k++){
            c.push_back(a[k]);
        }
    }
    for (int i = 0; i < n; i++) {         
        for (int j = 0; j < m; j++) {     
        cout << c[j*n + i] << ' ';
     }
    cout << endl;
}

}