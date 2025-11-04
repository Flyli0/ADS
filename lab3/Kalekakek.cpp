#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(vector<long long int>& houses, long long int K, long long int mid){
    long long int blocks = 1;
    long long int sum = 0;
    for(long long int i = 0; i<houses.size(); i++){
        if(sum+houses[i] <= mid){
            sum += houses[i];
        }
        else{
            blocks++;
            sum = houses[i];
        }
    }
    return blocks <= K;
}

long long int lowerbound(vector<long long int>& houses, long long int l, long long int r, long long int K){
    long long int mid = 0;
    while(l<r){
        mid = l + (r-l)/2;
        if(check(houses,K,mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    long long int N,K;
    cin >> N >> K;
    vector<long long int> houses;
    long long int maxic;
    long long int sum = 0,val;
    for(long long int i = 0; i<N; i++){
        cin >> val;
        if(i == 0){
            maxic = val;
        }
        maxic = max(maxic,val);
        sum += val;
        houses.push_back(val);
    }
    long long int l = maxic;
    long long int r = sum;
    cout << lowerbound(houses,l,r,K);
}