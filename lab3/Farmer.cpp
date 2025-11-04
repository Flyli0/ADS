#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(vector<pair<int,int>>& sqrs, int len, int K){
    int count = 0;
    for(auto it:sqrs){
        if(it.first <= len && it.second <= len){
            count ++;
        }
    }
    return count >= K;
}

int lowerbound(int K, vector<pair<int,int>>& sqrs){
    int l = 0, r = pow(10,9);
    int mid = 0;
    while(l<r){
        mid = l + (r-l)/2;
        if(check(sqrs,mid,K)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;

}

int main(){
    int totalsheep, needed,len = 0;
    int x1, y1, x2, y2;
    vector<pair<int,int>> lens;
    cin >> totalsheep >> needed; 
    for(int i = 0; i<totalsheep; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        lens.push_back(pair<int,int>(x2,y2));
    }
    cout << lowerbound(needed,lens);
}