#include <iostream> 
#include <vector>
#include <queue>
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
        rank.resize(0);
    }
    int find(int v){
        if(parent[v] == v){
            return v;
        }
        parent[v] = find(parent[v]);
        return parent[v]; 
    }

    void unite(int v1, int v2){
        v1 = find(v1);
        v2 = find(v2);

        if(v1 == v2) return;
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
 
struct Edge{
    int v,u,w;
};

bool comp(Edge& e1, Edge& e2){
    return e1.w < e2.w;
}

int kruscal(vector<Edge>& elist, int n){
    sort(elist.begin(),elist.end(),comp);
    int cost = 0;
    DSU dsu(n); 
    vector<Edge> mst;

    for(Edge& e:elist){
        if(dsu.find(e.v) != dsu.find(e.u)){
            dsu.unite(e.v,e.u);
            mst.push_back(e);
            cost+=e.w;
        }
    }
    return cost;
}

int main(){
    int n;
    vector<Edge> elist;
    vector<int> cost;
    cin >> n;
    for(int i = 0; i<n; i++){
        int val;
        cin >> val;
        cost.push_back(val);
    }
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            elist.push_back({i,j,cost[i]+cost[j]});
        }
    }
    /* for(auto& it: elist){
        cout << it.u << "--" << it.v << " cost " << it.w << endl;
    } */
    cout << kruscal(elist, n);
} 