#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n;
    stack<int> q;
    vector<int> answer;
    int age;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> age;
        if(!q.empty()){
            while(!q.empty()){
                if(age >= q.top()){
                    answer.push_back(q.top());
                    q.push(age);
                    break;
                }
                else{
                    q.pop();
                }
            }        
        }
        if(q.empty()){
            q.push(age);
            answer.push_back(-1);
        }
    }
    for(int i = 0; i<n; i++){
        cout << answer[i] << ' ';
    }
}