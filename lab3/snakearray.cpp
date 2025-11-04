#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int n,m, val;
    string answer = "";
    vector<int> findn;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> val;
        findn.push_back(val);
    }
    cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> val;
                arr[i][j] = val;
            }
    }
    for(const auto& it:findn){
        bool found = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(arr[i][j]==it){
                cout << i << ' ' << j << endl;
                found = true;
                }
                else if(i==n-1 && j == m-1 && !found){
                    cout << "-1" << endl;
                }
            }
        }
    }
}


/*'''''''''''''''''''''''''''''''''''''''''''''''''more optimal'''''''''''''''''''''''''''''''''''''''''''''''*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m, val;
    cin >> n;
    vector<int> findn(n);
    for (int i = 0; i < n; i++) cin >> findn[i];
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    unordered_map<int, pair<int,int>> pos; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            pos[arr[i][j]] = {i, j}; 
        }
    }
    for (int x : findn) {
        if (pos.count(x)) {
            cout << pos[x].first << " " << pos[x].second << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
