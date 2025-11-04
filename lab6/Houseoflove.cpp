#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j<high; ++j){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(vector<int>& a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);

        quicksort(a,low,pivot-1);
        quicksort(a, pivot + 1, high);
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
    quicksort(a,0,a.size()-1);
    quicksort(b,0,b.size()-1);

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