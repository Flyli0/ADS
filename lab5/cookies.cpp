#include <iostream> 
#include <queue>

using namespace std;

int main(){
    long long int n,m,val,sum = 0;
    string order, answer = "";
    cin >> n >> m;
    priority_queue<long long int,vector<long long int>,greater<long long int>> a;
    for(long long int i = 0; i<n; i++){
        cin >> order;
        if(order == "insert"){
            cin >> val;
            a.push(val);
            sum += val;
            if(a.size() > m){
                sum -= a.top();
                a.pop();
            }
        }
        if(order == "print"){
            answer += to_string(sum);
            answer += '\n';
        }
    }
    cout << answer;
}