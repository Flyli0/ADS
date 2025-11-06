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


int main(){
    string text; 
    cin >> text; 
    long long i = 1;
    long long count = 0;
    long long n = text.length();
    vector<long long> l = lps(text);
    while(i<n-1){
        long long s = i+1;
        if((i+1)%2==0 && l[i]>=(i+1)/2 && text.substr(0, s/2) + text.substr(0, s/2) == text.substr(0,s)){
            count++;
        }
        i++;
    }
    cout << count;
}