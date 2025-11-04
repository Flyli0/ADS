#include <iostream>
#include <vector>
#include <unordered_map> 
#include <cmath>

using namespace std;

int chtoi(int a){
    return a - 'a' + 1;
}

vector<long long> RabinCarp(string text, string pattern){
    int p       = 31;
    int mod     = 1e9 + 7;
    long long n = text.size();
    long long m = pattern.size();

    vector<long long> p_power(max(n,m)+1);
    vector<long long> text_hash(n+1,0);
    p_power[0] = 1;

    for(long long int i = 1; i<p_power.size(); i++){
        p_power[i] = (p_power[i-1]*p)%mod;
    }

    for(long long int i = 0; i<text_hash.size()-1; i++){
        text_hash[i+1] = (text_hash[i]+(chtoi(text[i])*p_power[i]))%mod;
    }

    long long pattern_hash = 0;

    for(long long int i = 0; i<pattern.size(); i++){
        pattern_hash = (pattern_hash+(chtoi(pattern[i])*p_power[i])%mod)%mod;
    }

    vector<long long> occurance;

    for(long long int i = 0; i<n-m+1; i++){
         long long curhash  = (text_hash[i+m] - text_hash[i] + mod)%mod;
         long long phash    = (pattern_hash*p_power[i])%mod;
         if(curhash%mod == phash%mod){
            occurance.push_back(i);
         }
    }
    return occurance;
}

int main(){
    long long n;
    vector<pair<long long,vector<string>>> answer;
    string val = "1";
    while(true){
        long long maxx = 0;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<string> temp; 
        for(long long i = 0; i<n; i++){
            cin >> val;
            temp.push_back(val); // тут паттерны лежат на диванах пока я весь ень сижу за ноутом и решаю эту лабу 
        }
        
        cin >> val;
        vector<pair<string, long long>> cur_patterns; //Я тут буду хранить паттерны и их частоту 

        for(long long i = 0; i<n; i++){
            vector<long long> a = RabinCarp(val,temp[i]);
            cur_patterns.push_back(make_pair(temp[i],a.size()));
            long long S = a.size();
            maxx = max(S,maxx);
        }
        vector<string> dominat;
        for(auto& it: cur_patterns){
            if(it.second == maxx){
                dominat.push_back(it.first);
            }
        }
        answer.push_back(pair<long long,vector<string>>(maxx,dominat));
    }

    for(auto& it: answer){
        cout << it.first << endl;
        for(auto& ut: it.second){
            cout << ut << endl;
        }
    }
}
