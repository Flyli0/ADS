#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<char> a;
    stack<char> b;
    string A;
    string B;
    cin >> A >> B;
    for(int i = 0; i < A.length(); i++){ 
        if(A[i] != '#'){
            a.push(A[i]);
        }
        else{
            a.pop();
        }
    }
    for(int i = 0; i < B.length(); i++){ 
        if(B[i] != '#'){
            b.push(B[i]);
        }
        else{
            b.pop();
        }
    }
    if(a == b){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}