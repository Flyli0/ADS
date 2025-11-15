#include <iostream>
#include <vector>
#include <queue> 
#include <sstream>

using namespace std;
void BFS(vector<vector<int>>& adj, int start){
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        cout << vertex; 
        for(int i = 0; i < adj[vertex].size(); i++){
            int neighbour = adj[vertex][i];
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main(){ 
    string line;
    int num;
    int vertnum;
    cin >> vertnum;
    getline(cin, line);
    vector<vector<int>> adj(vertnum+1);
    for(int i = 0; i<vertnum; i++){
        getline(cin,line);
        istringstream ss(line);
        while(ss >> num){
            adj[i].push_back(num);
        }
    }
    BFS(adj, 1);
}