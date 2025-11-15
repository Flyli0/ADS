#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    string answer = "";
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(n,0));
    vector<vector<int>>  adj(n+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        int one, two, three;
        cin >> one >> two >> three;
        bool can = false;
        if(mat[one-1][two-1] == 1 && mat[one-1][three-1] == 1 && mat[three-1][two-1] == 1){
            can = true;
        }
        if(can){
            answer+="YES";
        }
        else{
            answer += "NO";
        }
        answer+='\n';
    }
    cout << answer;
}