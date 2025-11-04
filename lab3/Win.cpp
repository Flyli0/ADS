#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


long long int upperbound(vector<long long int>& a, long long int target){
    
   long long int l = 0,r = a.size(), mid = 0;
    while(l<r){
        mid = l + (r-l)/2;
        if(target >= a[mid]){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l-1 ;
}


int main(){
    long long int N, power, roundnum;
    long long int val;
    vector<long long int> enemies;
    vector<long long int> rounds;
    string answer = "";
    cin >> N;
    for(long long int i = 0; i<N; i++){
        cin >> power;
        enemies.push_back(power);
    }
    sort(enemies.begin(),enemies.end());

    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + enemies[i];
    }

    cin >> roundnum;
    for(long long int i = 0; i<roundnum; i++){
        cin >> power;
        rounds.push_back(power);
    }

    for(long long int j = 0; j<roundnum; j++){
        long long int pow = 0;
        val =upperbound(enemies,rounds[j]);
        answer+=to_string(val);
        answer+=' ';
        pow = prefix[val];
        answer += to_string(pow);
        answer += '\n';
    }

    cout << answer;
}