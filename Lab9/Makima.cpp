#include <iostream> 
#include <vector>

using namespace std;

vector<long long> lps(string text){
    long long n = text.size();
    long long i = 1;
    long long len = 0;

    vector<long long> lps(n,0);

    while(i<n){
        if(text[len]==text[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i]=0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
    return lps;
}

int main(){
    vector<long long> answer;
    long long n;
    cin >> n;
    for(long long i = 0; i<n; i++){
        string val;
        long long K;
        cin >> val >> K;
        vector<long long> templps = lps(val);
        long long m = val.size();
        long long maxrep = templps[m-1];
        long long ans = (m-maxrep)*(K-1)+m;
        answer.push_back(ans);
    }
    for(const auto& a: answer){
        cout << a << endl;
    }
}