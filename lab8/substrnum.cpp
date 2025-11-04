#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int chtoi(char c){
    return c - 'a' +1;
}

long long sub(string text){
    int p   = 31;
    int mod = 1e9+7;
    long long int n   = text.size();

    vector<long long> text_hash(n+1,0);
    vector<long long> p_power(n+1);
    p_power[0] = 1;

    for(long long int i = 1; i<p_power.size(); i++){
        p_power[i] = (p_power[i-1]*p)%mod;
    }

    for(long long int i = 0; i<text_hash.size()-1; i++){
        text_hash[i+1] = (text_hash[i]+((chtoi(text[i])*p_power[i]))%mod)%mod;
    }
    
    unordered_set<long long> substr;
    
    for(long long int i = 0; i<n; i++){
        for(long long int j = i; j<n; j++){
            long long current = (text_hash[j+1]-text_hash[i]+mod)%mod;
            current = (current * p_power[n-(j+1)])%mod;
            substr.insert(current%mod);
        }
    }
    long long s = substr.size();
    return s;
}

int main(){
    string a;
    cin >> a;
    cout << sub(a);
}

//(╯°□°）╯︵ ┻━┻