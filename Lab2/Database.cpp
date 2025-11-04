#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    int n,l;
    string m;
    cin >> n ;
    stack<string> a;

    for(int i=0;i<n;i++){
        cin >> m;
        if(a.empty() || a.top()!=m){
            a.push(m);
        }
    }
    cout << "All in all: " << a.size() << endl;
    cout << "Students:" << endl;
    while(!a.empty()){
        cout << a.top() << endl;
        a.pop();
    }
}


