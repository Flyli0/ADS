#include <iostream> 
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    map<int,int> md;
    vector<int> answer;
    int n,val,key;
    pair<int,int> a;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> key;
        if(md.count(key) == 0){
            md.insert(pair<int,int>(key,1));
        }
        else{
            md[key]+=1;
        }
    }
    int maxx = 1;

    for(const auto& it : md){
        maxx = max(maxx, it.second);
    }

    for(const auto& it : md){
        if(maxx == it.second){
            answer.push_back(it.first);
        }
    }
    sort(answer.begin(),answer.end(), greater<int>());
    for(const auto& it : answer){
        cout << it << " ";
    }
}