#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& adj, int root, vector<bool>& globalVisited, int& answer){   
    queue<int> q;

    vector<int> parent(adj.size(), -1);
    vector<vector<int>> children(adj.size());
    vector<bool> visited(adj.size(), false);

    q.push(root);
    visited[root] = true;
    globalVisited[root] = true;      

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u : adj[v]){
            if(!visited[u]){
                visited[u] = true;
                globalVisited[u] = true;     
                parent[u] = v;
                children[v].push_back(u);
                q.push(u);
            }
        }
    }

    int count = 0;

    for (int i = 1; i < adj.size(); i++) {
        if (!visited[i]) continue; 

        if (i == root) {     
            count++;
        }
        else {
            int p = parent[i];
            if (children[i].size() > children[p].size())   
                count++;
        }
    }

    answer += count; 
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y); 
        adj[y].push_back(x);
    }

    vector<bool> visited(n+1, false);
    int result = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int root = i;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            vector<int> comp;
            comp.push_back(i);

            while(!q.empty()){
                int v = q.front();
                q.pop();

                for (int u : adj[v]) {
                    if(!visited[u]){
                        visited[u] = true;
                        q.push(u);
                        comp.push_back(u);

                        if (u < root) root = u;  
                    }
                }
            }
            BFS(adj, root, visited, result);
        }
    }

    cout << result;
}
