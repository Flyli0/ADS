#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long int upperbound(long long int K, vector<long long int>& prefix){
    long long int l = 1, r = prefix.size(), mid = 0;
    while(l<r){
        mid = l + (r-l)/2;
        if(prefix[mid]>K){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    long long int N,K,target;
    cin >> N >> K;
    vector<long long int> array;
    vector<long long int> prefix(N+1,0);
    long long int val;
    long long int answer = N+1;
    for(long long int i = 0; i<N; i++){
        cin >> val;
        array.push_back(val);
    }
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + array[i];
    }
    for(long long int j = 1; j<=N; j++){
        if(prefix[j] >= K){
            target = prefix[j] - K;
            int idx = upperbound(target,prefix);
            if(idx >  0){
                int i = idx - 1;
                answer = min(answer,j-i);
            }
        }
    }   
    cout << answer;
}





