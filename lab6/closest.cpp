#include <iostream> 
#include <vector> 

using namespace std;

int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low-1;
    for(int j = low; j<high; ++j){
        if(a[j]<= pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(vector<int>& a, int low, int high){
    if(low<high){
        int pivot = partition(a, low, high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot + 1, high);
    }
}

int main(){
    vector<int> a;
    int n,mindif;
    cin >> n;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;  
        mindif = abs(val);
        a.push_back(val);
    }
    quicksort(a,0,a.size()-1);
    for(int i = 0; i<n-1; i++){
        mindif = min(mindif,abs(a[i]-a[i+1]));
    }
    for(int i = 0; i<n-1; i++){
        if(abs(a[i]-a[i+1])==mindif){
            cout << a[i] << ' ' << a[i+1] << ' ';
        }
    }
}