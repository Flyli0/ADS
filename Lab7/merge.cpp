#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c;
    int i = 0;
    int j = 0;

    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        c.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        c.push_back(b[j]);
        j++;
    }
    return c;
}

int main(){
    int n,m;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        a.push_back(val);
    }
    cin >> m;
    vector<int> b;
    for(int i = 0; i<m; i++){
        int val;
        cin >> val;
        b.push_back(val);
    }
    vector<int> AB = merge(a,b);
    for(const auto& it : AB){
        cout << it << ' ';
    }
}