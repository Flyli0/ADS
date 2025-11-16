#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pathlen(vector<vector<int>>& adj, int& start, int& target){
    vector<bool> visited(adj.size(),false);
    queue<int> q;

    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        
       
        int sz = q.size();
        for(int k = 0; k<sz; k++){
            int vertex = q.front();
            q.pop();
            if(vertex == target){
                return 1;
            }
            for(int i = 0;  i<adj[vertex].size(); i++){
                int neighbour = adj[vertex][i];
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }   
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>  adj(n+1);

    for(int i = 0; i<m; i++){
        int vertex, path;
        cin >> vertex >> path;
        adj[vertex].push_back(path);
    }
    int start, finish;
    cin >> start >> finish;
    int y = pathlen(adj, start,finish);
    if(y == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
