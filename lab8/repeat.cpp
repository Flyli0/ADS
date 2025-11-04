#include <iostream>
#include <vector>
#include <cmath>
#include <string> 

using namespace std;

int chtoi(char c){
    return c - 'a' +1;
}

vector<long long> RC(string text, string pattern){
    int p   = 31;
    int mod = 1e9+7;
    long long n   = text.size();
    long long m   = pattern.size();

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
        pattern_hash = (pattern_hash + (chtoi(pattern[i]) * p_power[i]) % mod) % mod;
    }

    vector<long long> occurance;
    
    for(long long i = 0; i<n-m+1; i++){
        long long curhash = (text_hash[i+m]-text_hash[i]+mod)%mod;
        long long right_hash = (pattern_hash * p_power[i]) % mod;
        if(curhash == (pattern_hash * p_power[i]) % mod && text.substr(i,m)==pattern){
            occurance.push_back(i);
        }
    }
    return occurance;
}

int main(){
    string a;
    long long int n;
    vector<long long> answer;
    cin >> a >> n; 
    for(long long i = 0; i<n; i++){
        long long l, r;
        cin >> l >> r;
        string subs;
        subs = a.substr(l-1,r-l+1);
        vector<long long> aee = RC(a,subs);
        long long oc = aee.size();
        answer.push_back(oc);

    }
    for(auto& it: answer){
        cout << it << endl;
    }
}
//          (╯°□°）╯︵ ┻━┻