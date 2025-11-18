#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

    void recTop(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order){
        visited[v] = true;
        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i];
            if(!visited[u]){
                recTop(u,adj,visited,order);
            }
        }
        order.push_back(v);
    }

    void topSort(vector<vector<int>>& adj){
        int v = adj.size();
        vector<bool> visited(v,false);
        vector<int> order;

        for(int i = 0; i<v; i++){
            if(!visited[i]){
                recTop(i,adj,visited,order);
            }
        }
        reverse(order.begin(),order.end());
        for(int i = 0; i<order.size(); i++){
            cout << order[i] << ' ';
        }
    }

int main(){
    vector<vector<int>> adj = {{1}, {2}, {}, {2, 4}, {}};

    topSort(adj);
}