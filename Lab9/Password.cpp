#include <iostream>
#include <vector>

using namespace std;

vector<long long> lps(string str){
    long long n     = str.size();
    long long len   = 0;
    long long i     = 1;

    vector<long long> lps(n,0);

    while(i<n){
        if(str[len]==str[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

vector<long long> KMP(string str, string pat){
    long long n = str.size();
    long long m = pat.size();
    long long i = 0, j = 0;

    vector<long long> answer;
    vector<long long> p_lps = lps(pat);

    while(i<n){
        if(str[i]==pat[j]){
            i++;
            j++;
            if(j == m){
                answer.push_back(i-j);
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
    return answer;
}

int main(){
    long long n; 
    string password, paper;
    cin >> password >> n >> paper;
    if(KMP(paper,password).size()>=n){
        cout << "YES";
    }
    else{
        cout <<  "NO";
    }
}