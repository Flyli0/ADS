#include <iostream> 
#include <vector> 
#include <sstream>

using namespace std; 

int main(){
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> adj(n);
    int num;
    string line;
    for(int i = 0; i<n; i++){
        getline(cin,line);
        istringstream ss(line);
        while(ss >> num){
            adj[i].push_back(num);
        }
    } 

    vector<pair<int, int>> edjelist;
    
}