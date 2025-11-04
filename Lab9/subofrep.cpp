#include <iostream>
#include <vector>


using namespace std;

vector<long long> lps(string& a)
{
    long long n     = a.size();
    long long i     = 1;
    long long len   = 0;
    vector<long long> lps(n,0);

    while(i<n){
        if(a[i]==a[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
    return lps;
}

bool KMP(string& text, string& pat, long long reps){
    
    long long n = text.size();
    long long m = pat.size();
    long long i = 0, j = 0;

    vector<long long> p_lps = lps(pat);
    long long maxx = n * reps;

    while(i<maxx){
        char ca = text[i%n];
        if(ca==pat[j]){
            i++;
            j++;
            if(j == m){
                return true;
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
    return false;
}

int main(){
    string rep, pat;
    cin >> rep >> pat;
    string add = rep;
    long long base = (rep.size()+pat.size()-1)/rep.size();
    long long repnum;
    for(long long i = 0; i<=2; i++){
        repnum = base + i;
        if(KMP(rep,pat,repnum)){
            cout << repnum;
            return 0;
        }
        rep+=rep;
    }
    cout << -1;
}