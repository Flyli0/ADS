#include <iostream> 
#include <vector>

using namespace std;

int partition(vector<char> a, int low, int high){
    char pivot = a[high];
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

void quicksort(vector<char> a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);

        quicksort(a, low, pivot -1);
        quicksort(a,pivot+1,high);
    }
}

int main(){
    char H;
    int n;
    char answer = '0';
    vector<char> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        char val;
        cin >> val;
        a.push_back(val);
    }
    cin >> H;
    for(int i = 0; i<n; i++){
        if(int(H)<int(a[i])){
            answer = a[i];
            break;
        }
    }
    if(answer == '0'){
        cout << a[0];
    }
    else{
        cout << answer;
    }
}