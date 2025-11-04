#include <iostream>
#include <vector>

using namespace std;

int partition(vector<char>& a, int low, int high){
    char pivot = a[high];
    int i = low - 1;
    for(int j = low; j<high; ++j){
        if(int(a[j])<=int(pivot)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(vector<char>& a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);

        quicksort(a, low, pivot -1);
        quicksort(a,pivot+1,high);
    }
}

int main(){
    string n;
    cin >> n;
    vector<char> a;
    for(int i = 0; i < n.length(); i++){
        a.push_back(n[i]);
    }
    quicksort(a,0,a.size()-1);
    for(const auto& it : a){
        cout << it;
    }
}