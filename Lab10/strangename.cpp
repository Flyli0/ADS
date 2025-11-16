#include <iostream> 
#include <queue>
#include <vector>
#include <stack>

using int64 = long long;
using namespace std; 

stack<int64> path( int& start, int& target){
    vector<bool> visited(2e5+1);
    vector<int64> parent(2e5+1, -2);
    queue<int64> q;
    stack<int64> path;
    visited[start] = true;
    parent[start] = -1;
    q.push(start);
    
    while(!q.empty()){
        int64 sz = q.size();

            int64 vertex = q.front();
            q.pop();
            if(vertex == target){
                int64 cur = vertex;
                while(parent[cur]!=-1){
                    path.push(cur);
                    cur = parent[cur];
                }

                return path;
            }
            else{
                if(  vertex*2 < visited.size() && visited[vertex*2] == false) {
                    q.push(vertex*2);
                    visited[vertex*2] = true;
                    parent[vertex*2] = vertex;
                }
                if(  vertex-1 >= 0 && visited[vertex-1] == false){
                    q.push(vertex-1);
                    visited[vertex-1] = true;
                    parent[vertex-1] = vertex;
                }
        }
    }   
    return path;
}

int main(){
    int n, m,count = 0;
    cin >> n >> m;
    vector<vector<int>>  adj(n+1); 
    stack<int64> ans = path(n,m);
    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}