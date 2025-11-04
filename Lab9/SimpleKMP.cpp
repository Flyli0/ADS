#include <iostream>
#include <vector> 

using namespace std;

vector<long long> lps(string& str){
    long long i = 1;
    long long n = str.size();
    long long len = 0;

    vector<long long> lps(n,0);

    while(i<n){
        if(str[len] == str[i]){
            len++;
            lps[i]= len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    } 
    return lps;
}

vector<long long> KMP(string& str, string& pat){
    
    vector<long long> p_lps = lps(pat);
    vector<long long> result;

    long long n = str.size();
    long long m = pat.size();
    long long i = 0;
    long long j = 0;

    while(i<n){
        if(str[i] == pat[j]){
            j++;
            i++;
            if(j == m){
                result.push_back(i-j+1);
                j = p_lps[j - 1];
            }
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = p_lps[j-1];
            }
        }
    }
    return result;
}

int main(){
    string text;
    string pat;
    cin >> text >> pat;
    cout << KMP(text, pat).size() << endl;
    for(auto& ut: KMP(text, pat)){
        cout << ut << ' ';
    }
}