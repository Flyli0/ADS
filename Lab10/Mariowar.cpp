#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    vector<vector<int>> mat(m+2, vector<int>(n+2,0));
    queue<pair<int,int>> marios;

    int m_count = 0;
    int minutes = 0;

    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                m_count++;
            }
            if(mat[i][j] == 2){
                marios.push(make_pair(i,j));
            }
        }
    }
    bool repl = false;

    while(!marios.empty()){
        int sz = marios.size();
        if(repl){
            minutes++;
            repl = false;
        }
        for(int k = 0; k<sz; k++){
            int i = marios.front().first;
            int j = marios.front().second;
            marios.pop();
                if(mat[i][j] == 2){
                    
                    if(mat[i][j+1] == 1){
                        m_count--;
                        mat[i][j+1] = 2;
                        repl = true;
                        marios.push(make_pair(i,j+1));
                    }
                    if(mat[i+1][j] == 1){
                        m_count--;
                        mat[i+1][j] = 2;
                        repl = true;
                        marios.push(make_pair(i+1,j));
                    }
                    if(mat[i][j-1] == 1){
                        m_count--;
                        mat[i][j-1] = 2;
                        repl = true;
                        marios.push(make_pair(i,j-1));
                    }
                    if(mat[i-1][j] == 1){
                        m_count--;
                        mat[i-1][j] = 2;
                        repl = true;
                        marios.push(make_pair(i-1,j));
                    }
                }
                }
            }
    if(m_count == 0){
        cout << minutes;
    }
    else{
        cout << -1;
    }
}