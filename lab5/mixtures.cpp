#include <iostream> 
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<long long int,vector<long long int>,greater<long long int>> a;
    for(long long int i = 0; i<n; i++){
        long long int val;
        cin >> val;
        a.push(val);
    }
    long long int count = 0;
    while(a.size()>=1){
        if(a.size() == 1 && a.top()<m){
            count = -1;
            break;
        }
        if(a.top()>=m){
            break;
        }
        int first = a.top();
        a.pop();
        int second = 2*a.top();
        a.pop();
        a.push(first + second); 
        count++;
    }
    cout << count;
}