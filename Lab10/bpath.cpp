#include <iostream> 
#include <queue>
#include <vector>

using namespace std; 

int pathlen(vector<vector<int>>& adj, int& start, int& count, int& target){
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
                return count;
            }
            for(int i = 0;  i<adj[vertex].size(); i++){
                int neighbour = adj[vertex][i];
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        count++;
    }   
    return -1;
}

int main(){
    int n, m, target , count = 0;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    vector<vector<int>>  adj(n+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    cin >> m >> target;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] == 1){
                adj[i+1].push_back(j+1);
            }
        }
    }
    
    cout << pathlen(adj,m,count,target);
}