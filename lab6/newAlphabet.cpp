#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<char> vow = {'a','e','o','i','u'};
int partition(vector<int>& a, int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j<high; ++j){
        if( a[j]<=pivot){
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
    string a;
    int n,s;
    cin >> n;
    cin >> a;
    vector<int> vowel;
    vector<int> con;
    for(auto i: a){
        if(vow.count(i)>0){
             vowel.push_back(int(i));
        }
        else{
            con.push_back(int(i));
        }
    }
    quicksort(vowel,s,vowel.size()-1);
    quicksort(con,s,con.size()-1);
    for(const auto& it: vowel){ 
        cout << char(it);
    }
    for(const auto& it: con){ 
        cout << char(it);
    }
}