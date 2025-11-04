#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
using namespace std;
int main(){
    vector<int> primes;
    int n;
    cin >> n;
    vector<bool> isprime(20000000,true);
    for(int i = 2; i<20000; i++){
        for(int j = 2;j<1000; j++){
            isprime[i*j]=false;
        }
    }
    for(int i = 1; i<20000; i++){
        if(isprime[i]==1){
        primes.push_back(i);
        }
    }
    cout << primes[n];
}
