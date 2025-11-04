#include <iostream> 
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int> list;
    int n, val, num, mini, minni, ans;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> val;
        list.push_back(val);
    }
    cin >> num;
    mini = abs(num - list[0]);
    minni = mini;
    ans = 0;
    for(int i = 1; i<=n; i++){
        if(mini != minni){
            ans = i-1;
            minni = mini;
        }
        mini = min(abs(num - list[i]),mini);   
    }
    cout << ans;
}