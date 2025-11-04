#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void binshuf(vector<int>& a,vector<int>& b,int l, int r ){
    if(l>r){
        return;
    }
    int mid = l + (r-l)/2;
    b.push_back(a[mid]);
    binshuf(a,b,mid+1,r);
    binshuf(a,b,l,mid-1);
}

int main(){
    vector<int> arr;
    vector<int> ans;
    int n,m;
    cin >> n;
    for(int i = 0; i<pow(2,n)-1; i++){
        cin >> m;
        arr.push_back(m);
    }
    int r = arr.size()-1;
    int l = 0;
    sort(arr.begin(),arr.end());
    binshuf(arr,ans,l,r);
    for(const auto& it: ans){
        cout << it << ' ';
    }
}