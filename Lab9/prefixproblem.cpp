#include <iostream>
#include <vector>
#include <algorithm>

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

int main(){
    string a;
    cin >> a;
    vector<long long> al = lps(a);
    cout << a.size()-al[a.size()-1];
}