#include <iostream> 
#include <vector> 
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int prim(vector<vector<pii>>& adj, int start, int n){
    vector<bool> visited(n,false);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    int cost = 0;

    pq.push({0,start});

    while(!pq.empty()){
        pii v = pq.top();
        pq.pop();

        if(visited[v.second]) continue;

        visited[v.second] = true;

        if(v.first != 0){
             cost+= v.first;
        }

        for(int i = 0; i<adj[v.second].size(); i++){
            pii u = adj[v.second][i];
            int to = u.first;
            int weight = u.second;
            if(!visited[to]){
                pq.push({weight,to});
            }
        }
    }
    return cost;
}
int main(){
    int n;
    cin >> n;
    vector<vector<pii>> adj(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int val;
            cin >> val;
            adj[i].push_back({j,val});
            adj[j].push_back({i,val});
        }
    }
    cout << prim(adj,0,n);
}