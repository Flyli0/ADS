#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool check(vector<long long int>& islands, long long int K, long long int mid){
    long long int flies = 0;
    long long int sum = 0;
    long long int i = 0;
    while(i<islands.size()){
        flies+=(islands[i] + mid - 1) / mid;
        i++;
    }
    return flies <= K;
}

long long int lowerbound(vector<long long int>& islands, long long int l, long long int r, long long int K){
    sort(islands.begin(),islands.end());
    long long int mid = 0;
    while(l<r){
        mid = l + (r-l)/2;
        if(check(islands,K,mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    long long int n, flights, presentnum, summ = 0, maxx;
    vector<long long int> islands;
    cin >> n >> flights;
    for(long long int i = 0; i<n; i++){
        cin >> presentnum;
        if(i == 0){
            maxx = presentnum;
        }
        maxx = max(maxx,presentnum);
        islands.push_back(presentnum);
    }
    long long int l = 1;
    long long int r = maxx;
    cout << lowerbound(islands,l,r,flights);
}