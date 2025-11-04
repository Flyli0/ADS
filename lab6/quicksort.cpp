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
    vector<int> arr;
    arr = {2,1,5,4,3,9,6,8,7,10};
    quicksort(arr,0,arr.size()-1);
    for(const auto& it: arr){
        cout << it << ' ';
    }
}