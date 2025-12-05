#include <iostream>
#include <vector> 
#include <queue>
#define INF 1e9 
using namespace std;

// relaxation method 

vector<int> Bellman(int start, vector<vector<int>>& edjes, int n){
    vector<int> dist(n,INF);
    dist[start] = 0;

    for(int i = 0; i<n; i++){
        for(auto& edje: edjes){
            int u = edje[0];
            int v = edje[1];
            int w = edje[2];
            if(dist[u] != INF && dist[v] > dist[u] + w){  //relaxation 
                if(i == n-1){
                    cout << "Niggative cycle\n";
                    return dist; 
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 5},
        {3, 1, -15},
        {2, 4, 3},
        {4, 3, 4},
        {3, 5, 11}
    };

    vector<int> BF = Bellman(0,edges,6);
    for(auto& it: BF){
        cout << it << ' ';
    }
}