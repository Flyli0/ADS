#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std; 

int islandcount(vector<vector<int>>& mat, vector<pair<int,int>>& ones, int n, int m){
    vector<vector<bool>> visited(n+2,vector<bool> (m+2, false));
    queue<pair<int,int>> q;
    int count = 0;

    for(int j = 0; j<ones.size(); j++){
        if(!visited[ones[j].first][ones[j].second]){
            count++;
            q.push(ones[j]);
            visited[ones[j].first][ones[j].second] = true;
            while(!q.empty()){
                pair<int,int> vert = q.front();
                q.pop();
                int x = vert.first;
                int y = vert.second;
                if(mat[x+1][y]==1 && !visited[x+1][y]){
                    q.push(make_pair(x+1,y));
                    visited[x+1][y] = true;
                }
                if(mat[x-1][y]==1 && !visited[x-1][y]){
                    q.push(make_pair(x-1,y));
                    visited[x-1][y] = true;
                }
                if(mat[x][y+1]==1 && !visited[x][y+1]){
                    q.push(make_pair(x,y+1));
                    visited[x][y+1] = true;
                }
                if(mat[x][y-1]==1 && !visited[x][y-1]){
                    q.push(make_pair(x,y-1));
                    visited[x][y-1] = true;
                }
            }
        }
    } 

    return count;
}


int main(){
    int n, m;
    cin >> n >> m;
    string input;
    vector<vector<int>> mat(n+2,vector<int> (m+2,0));
    vector<pair<int,int>> ones;
    for(int i = 1; i<n+1; i++){
        cin >> input;   
        for(int j = 1; j<m+1; j++){
            mat[i][j] = input[j-1] - '0';
            if(mat[i][j] == 1){
                ones.push_back(make_pair(i,j));
            }
        }
    }
    cout << islandcount(mat,ones,n,m);
}