#include <iostream>
#include <vector>
#include <queue> 
#define INF 1e9

using namespace std; 
typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& adj, int start,int n){
    vector<int> dist(n,INF);
    priority_queue<pii,vector<pii>, greater<pii>> pq; 

    dist[start] = 0;
    pq.emplace(0,start);
    while(!pq.empty()){

        pii top = pq.top();
        pq.pop();

        int distance = top.first;
        int u = top.second;

        if(distance > dist[u]) continue;

        for(pii& neighbour: adj[u]){
            int v = neighbour.first;
            int w = neighbour.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u]+w;
                pq.emplace(w,v);
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<pii>> adj = {
        {{1, 4}, {2, 2}},
        {{2, 5}, {3, 10}},
        {{4, 3}},
        {{5, 11}},
        {{3, 4}},
        {}
    };

    vector<int> dist = dijkstra(adj,0, 6);
    for(const auto& it:dist){
        cout << it << ' ';
    }
}