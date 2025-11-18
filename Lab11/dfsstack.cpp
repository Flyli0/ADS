#include <iostream>
#include <vector>
#include <stack>

using namespace std;
    void DFS(int start, vector<vector<int>>& adj){
        int v = adj.size();
        vector<bool> visited(v,false);
        stack<int> st;

        st.push(start);

        while(!st.empty()){
            int vert = st.top();
            st.pop();
            if(!visited[vert]){
                visited[vert] = true;
                cout << vert << ' ';
            }
            for(int i = adj[vert].size()-1; i>=0; i--){
                int neighbour = adj[vert][i];
                if(!visited[neighbour]){
                    st.push(neighbour);
                }
            }
        }
    }
int main(){
    vector<vector<int>> adj = {
        {1, 2},
        {0, 2},
        {0, 1, 3, 4},
        {2},
        {2}
    };
    DFS(0,adj);
}