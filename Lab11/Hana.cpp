#include <iostream> 
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;


/*class DSU{
    private:
    vector<int64> parent;
    vector<int64> rank;
    public:
    DSU(int64 n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int64 i = 0; i<n+1; i++){
            parent[i] = i;
        }
    }
    
    int find(int64 v){
        if(parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int64 v1, int64 v2){
        v1 = find(v1);
        v2 = find(v2);

        if(v1 == v2){
            return;
        }
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
    }
};

struct edge{
    int64 u,v,w;
};

bool comp(edge e1, edge e2){
    return e1.w < e2.w;
}

int64 kruscal(vector<edge> elist, int64 n){
    sort(elist.begin(),elist.end(),comp);
    int64 total = 0;
    DSU dsu(n);
    vector<edge> mst;
    for(edge& e: elist){
        if(dsu.find(e.v) != dsu.find(e.u)){
            dsu.unite(e.v,e.u);
            total += e.w;
            mst.push_back(e);
        }
    }
    
    return total;
}

int main(){
    int64 n, m;
    cin >> n >> m;
    vector<edge> elist;

    for(int64 i = 0; i<m; i++){
        int64 l,r,weight;
        cin >> l >> r >> weight;
        for(int64 i = l; i< r; i++){
                elist.push_back({i,i+1,weight});     
        }
    }
   

    cout << kruscal(elist,n);
} */



long long prim(int n, vector<vector<pii>>& adj) {
    vector<bool> used(n+1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, 1}); 
    long long total = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (used[v]) continue;
        used[v] = true;
        total += w;

        for (auto& [to, weight] : adj[v]) {
            if (!used[to]) {
                pq.push({weight, to});
            }
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n+1);

    for (int k = 0; k < m; k++) {
        int l, r, w;
        cin >> l >> r >> w;

        for (int v = l; v < r; v++) {
            adj[v].push_back({v+1, w});
            adj[v+1].push_back({v, w});
        }
    }

    cout << prim(n, adj);
}