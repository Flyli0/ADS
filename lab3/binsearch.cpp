#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool findnum(vector<int>& a,int target){
    sort(a.begin(), a.end());
    int l = 0, r=a.size() - 1, mid = 0;
    while(l<=r){
        mid = l + (r-l)/2;
        if(target == a[mid]){
            return true;
        }
        else if(target < a[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        
    }
    return false;
}

int main(){
    int n, val;
    cin >> n;
    vector<int> a;
    for(int i = 0; i<n; i++){
        cin >> val;
        a.push_back(val);
    }
    int t;
    cin >> t;
    string z = (findnum(a,t))? "Yes": "No";
    cout << z;
}