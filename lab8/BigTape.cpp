#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int chtoi(char c){
    return c - 'a'+ 1;
}

vector<long long> RC(string text, string pattern){
    int p       = 31;
    int mod     = 1e9 + 7;
    long long n = text.size();
    long long m = pattern.size();

    vector<long long> text_hash(n+1,0);
    vector<long long> p_power(max(n,m)+1);
    
    p_power[0] = 1;

    for(long long i = 1; i<p_power.size(); i++){
        p_power[i] = (p_power[i-1]*p)%mod;
    }

    for(long long i = 0; i<text_hash.size()-1; i++){
        text_hash[i+1] = (text_hash[i]+(chtoi(text[i])*p_power[i]))%mod;
    }

    long long pattern_hash = 0;

    for(long long i = 0; i<pattern.size(); i++){
        pattern_hash = (pattern_hash+(chtoi(pattern[i])*p_power[i])%mod)%mod;
    }
    
    vector<long long> occurance;

    for(int i = 0; i<n-m+1; i++){
        long long curhash = (text_hash[i+m]-text_hash[i]+mod)%mod;
        long long phash = (pattern_hash*p_power[i])%mod;
        if(curhash%mod == phash%mod){
            occurance.push_back(i);
        }
    }
    return occurance;
}

int main(){
    int n;
    string longest;
    cin >> longest;
    cin >> n;
    string check(longest.size(),'*');
    for(int i = 0; i<n; i++){
        string shorter;
        cin >> shorter;
        vector<long long> a = RC(longest,shorter);
        for(auto& it: a){
            check.replace(it,shorter.size(),shorter);
        }
    }
    if(check == longest){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}