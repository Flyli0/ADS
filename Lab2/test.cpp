#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n = 53;
    vector<int> av;
    int a;
    for(int i = 0; i<n; i++){
        cin >> a;
        av.push_back(a);
    }
    sort(av.begin(),av.end());
    for(const auto& it:av){
        cout << it << ' ';
    }
}