#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pathlen(vector<pair<int,vector<int>>>& adj, int& start, int& redc, int& count){
    vector<bool> visited(adj.size(),false);
    queue<int> q;

    if(redc == 0){
        return -1;
    }
    

    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
              
        int sz = q.size();
        for(int k = 0; k<sz; k++){
            int vertex = q.front();
            q.pop();
            if(adj[vertex].first == 1){
                return count;
            }
            for(int i = 0;  i<adj[vertex].second.size(); i++){
                int neighbour = adj[vertex].second[i];
                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        count ++;
    }   
    return -1;
}

int main(){
    int red     = 1;
    int black   = 0;
    int redcount = 0;
    string answer = "";
    int vertices, edjes, queries;
    cin >> vertices >> edjes >> queries;
    vector<pair<int,vector<int>>> adj(vertices+1);

    for(int i = 0; i<edjes; i++){
        int vertex1, vertex2; 
        cin >> vertex1 >> vertex2;
        adj[vertex1].second.push_back(vertex2);
        adj[vertex2].second.push_back(vertex1);
    }

    for(int i = 0; i<adj.size(); i++){
        adj[i].first = 0;
    }

    

    for(int i = 0; i<queries; i++){
        int vertex, query;
        cin >> query >> vertex;
        if(query == 1){
            adj[vertex].first = 1;
            redcount++;
        }
        else{
            int count = 0;
            answer+=to_string(pathlen(adj,vertex,redcount,count));
            answer+='\n';
        }
    }
    
    cout << answer;
}