#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <unordered_map>


using namespace std;


long long int Hashfunc(string val){
    long long int H = 0;
    long long int base = 1;
    long long int mult = 11;
    int mod = 1e9+7;
    
    for(long long int i = 0; i<val.length(); i++){
        H += ((val[i]-47)*base)%mod;
        base=(base*mult)%mod;
    }
    H = H % mod;
    return H;
}

int main(){
    long long int n; 
    cin >> n;

    unordered_map<string, long long int> a;
    vector<pair<string,long long int>> answer;
    vector<pair<string,long long int>> str;

    for(long long int i = 0; i<2*n; i++){
        string val1;
        cin >> val1;
        str.push_back(make_pair(val1,Hashfunc(val1)));
        a.insert(make_pair(val1,Hashfunc(val1)));
    }

    for(auto& it:str){
        string hashStr = to_string(it.second);
        if(a.count(hashStr)>0){
            answer.push_back({it.first, stoll(hashStr)});
        }
    }


    for (size_t i = 0; i < n; i++) {
        cout << "Hash of string \"" << answer[i].first << "\" is " << answer[i].second;
        if (i + 1 != answer.size()) cout << "\n";
    }
}

//                (╯°□°）╯︵ ┻━┻