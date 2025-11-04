#include <iostream>
#include <vector>
using namespace std;
int main(){
vector<int> primes;
vector<int> superprimes;
vector<bool> isPrime(20001,true);
isPrime[0] = false;
isPrime[1] = false;
for(int i = 2; i<20001; i++){
    if(isPrime[i]){
        primes.push_back(i);
    }
    for(int j = i*2; j<=20001; j+=i){
        isPrime[j]=false;
    }
}
for(int ind = 2; ind<primes.size(); ind++){
   for(const auto &i : primes){
    if(ind==i){
        superprimes.push_back(primes[ind-1]);
    }
}
}
int n;
cin >> n;
cout << superprimes[n-1];
}