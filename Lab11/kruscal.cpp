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
    vector<Edge> edges;

    edges.push_back({0, 1, 13});
    edges.push_back({0, 2, 12});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 14});
    edges.push_back({2, 3, 9});

    cout << kruscal(edges, 4) << endl;
} 




