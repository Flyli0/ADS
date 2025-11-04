#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int chtoi(char c){
    return c - 'a' +1;
}

vector<long long int> RC(string text, string pattern){
    int p   = 31;
    int mod = 1e9+7;
    long long int n   = text.size();
    long long int m   = pattern.size();

    vector<long long> text_hash(n+1,0);
    vector<long long> p_power(max(n,m)+1);
    p_power[0] = 1;

    for(long long int i = 1; i<p_power.size(); i++){
        p_power[i] = (p_power[i-1]*p)%mod;
    }

    for(long long int i = 0; i<text_hash.size()-1; i++){
        text_hash[i+1] = (text_hash[i]+(chtoi(text[i])*p_power[i]))%mod;
    }

    long long pattern_hash = 0;
    
    for(long long int i = 0; i<pattern.size(); i++){
        pattern_hash = (pattern_hash + (chtoi(pattern[i]) * p_power[i]) % mod) % mod;
    }

    vector<long long int> occurance;
    
    for(int i = 0; i<n-m+1; i++){
        long long curhash = (text_hash[i+m]-text_hash[i]+mod)%mod;
        long long right_hash = (pattern_hash * p_power[i]) % mod;
        if(curhash%mod == right_hash%mod){
            occurance.push_back(i);
        }
    }
    return occurance;
}

int main(){
    string text1,text2,pattern;
    cin >> text1 >> text2 >> pattern;
    vector<long long int> occ1 = RC(text1,pattern);
    vector<long long int> occ2 = RC(text2,pattern);
    long long int i = 0, j = 0;
    long long int count = 0;
    while(i<occ1.size() && j<occ2.size()){
        if(occ1[i]>occ2[j]){
            j++;
        }
        else if(occ1[i]<occ2[j]){
            i++;
        }
        else{
            count++;
            i++;
            j++;
        }
    }
    cout << count;
}