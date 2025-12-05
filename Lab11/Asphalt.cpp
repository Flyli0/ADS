#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class DSU{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
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
     int n,m;
     int price1, price2;
     cin >> n >> m >> price1 >> price2;
     vector<Edge> elist;
     for(int i = 0; i<m; i++){
        int from, to, len, total_cost;
        string comm;
        cin >> comm >> from >> to >> len;
        if(comm == "big"){
            total_cost = len*price1;
        }
        else if(comm == "small"){
            total_cost = len*price2;
        }
        else if(comm == "both"){
            total_cost = len * min(price1,price2);
        }
        elist.push_back({from,to,total_cost});
     }
     
     cout << kruscal(elist,n);
}