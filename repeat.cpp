#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std; 

/* void merge(vector<int>& arr, int l, int r, int mid){
    int n = mid - l + 1;
    int m = r - mid; 

    vector<int> L(n), R(m);

    for(int i = 0; i<n; i++){
        L[i] = arr[l+i];
    }
    for(int i = 0; i<m; i++){
        R[i] = arr[i+mid+1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n && j<m){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<m){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arr, int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}

int main(){
    vector<int> temp = {2,3,5,2,3,5,6};
    mergesort(temp,0,temp.size()-1);
    for(const auto& t: temp){
        cout << t << ' ';
    }
}
 */

 int chtoi(char c){
    return c - 'a' + 1;
}
/*  vector<int> RC(string text, string pat){
    int p = 31;
    long long mod = 1e9 + 7;
    int n = text.size();
    int m = pat.size();

    vector<long long> p_power(n+1);
    vector<long long> text_hash(n+1,0);
    p_power[0] = 1;

    for(int i = 1; i<p_power.size(); i++){
        p_power[i] = (p_power[i-1]*p)%mod;
    }

    for(int i = 0; i<text_hash.size()-1; i++){
        text_hash[i+1] = (text_hash[i]+(chtoi(text[i])*p_power[i]))%mod;
    }

    int pat_hash = 0;
    for(int i = 0; i<pat.size(); i++){
        pat_hash = (pat_hash+(chtoi(pat[i])*p_power[i])%mod)%mod;
    }

    vector<int> occ;

    for(int i = 0; i<n-m+1; i++){
        int curhash = (text_hash[i+m] - text_hash[i] + mod) % mod;
        int rhash = (pat_hash*p_power[i])%mod;
        if(curhash%mod == rhash%mod){
            occ.push_back(i);
        }
    }
    return occ;
 }

int main(){
    string text = "asdfnasdfas";
    string pat = "as";
    for(const auto& it: RC(text,pat)){
        cout << it << ' ';
    }
} */

/* vector<int> lps(string text){
    int n = text.size();
    int len = 0;
    int i = 1;

    vector<int> lps(n,0);

    while(i<n){
        if(text[i] == text[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

vector<int> KMP(string text, string pat){
    int n = text.size();
    int m = pat.size();
    int i = 0;
    int j = 0;

    vector<int> plps = lps(pat);
    vector<int> answer;

    while(i<n){
        if(pat[j]==text[i]){
            j++;
            i++;
            if(j == m){
                answer.push_back(i-j);
                j = plps[j-1];
            }
        }
            else{
                if(j == 0){
                    i++;
                }
                else{
                    j = plps[j-1];
                }
            }
        }
        return answer;
    }
    

int main(){
    string text = "fiwdfie";
    string pat = "fi";
    for(const auto& it: KMP(text,pat)){
        cout << it << ' ';
    }
} */

void BFS(vector<vector<int>>& adj, int start){
    int v = adj.size();
    vector<bool> visited(v,false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        cout << vertex << ' ';
        for(int i = 0; i<adj[vertex].size(); i++){
            int neighbour = adj[vertex][i];
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    vector<vector<int>> adj = {{1},{0,2},{1}};
    BFS(adj,1);
}