#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_rec(int v, vector<vector<int>>& adj, vector<bool>& visited){
    if(visited[v]){
        return;
    }
    cout << v;
    visited[v] = true;
    for(int i = 0; i<adj[v].size(); i++){
        int u = adj[v][i];
        if(!visited[u]) dfs_rec(u,adj,visited);
    }
}

void DFS(int start, vector<vector<int>>& adj){
    int v = adj.size();
    vector<bool> visited(v,false);

    dfs_rec(start, adj, visited);
}

int main(){

    vector<vector<int>> adj = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };
    DFS(0,adj);
}