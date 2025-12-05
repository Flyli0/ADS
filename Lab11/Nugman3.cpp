#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int v){
        if(parent[v] == v){
            return v;
        }
        parent[v] = find(parent[v]);
        return parent[v]; 
    }

    bool unite(int v1, int v2){
        v1 = find(v1);
        v2 = find(v2);

        if(v1 == v2) return false;
        else{
            if(rank[v1] < rank[v2]){
                parent[v1] = v2;
            } 
            else if(rank[v2] < rank[v1]){
                parent[v2] = v1;
            }
            else{
                parent[v2] = v1;
                rank[v1]++;
            }
            return true;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    DSU dsu(n);

    vector<bool> active(n+1, false);
    vector<int> answer(n);

    int components = 0;

    for (int i = n; i >= 1; i--) {
        answer[i-1] = components;
        int v = i;
        active[v] = true;
        components++;  


        for (int u : g[v]) {
            if (active[u]) {
                if (dsu.unite(u, v)) {
                    components--; 
                }
            }
        }
        
    }

    for (int x : answer)
        cout << x << "\n";
}
