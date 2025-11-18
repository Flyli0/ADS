#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(vector<vector<int>> adj){
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    bool possible = false;

    q.push(1);
    visited[1] = true;
    for(int k = 1; k<adj.size(); k++){
        for(int s = 0; s<adj[k].size(); s++){
            vector<vector<int>> adjj = adj;
            adjj[k][s] = -1;
            int count = 0;
            while(!q.empty()){
                
                int vert = q.front();
                q.pop();
                
                for(int i = 0; i<adj[vert].size(); i++){
                    int neighbour = adj[vert][i];
                    if(!visited[neighbour] && neighbour!=-1){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                    else if(neighbour!=-1){
                        count++;
                    }
                } 
            }
            if(count == 0){
                possible = true;
            }
        }
    }
    return possible;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i<m; i++){
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }
    if(BFS(adj)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}