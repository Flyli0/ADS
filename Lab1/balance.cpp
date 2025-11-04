#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main(){
stack<char> balance;
string test;
cin >> test;
for(int i = 0; i<test.length(); i++){
   if(balance.empty() || balance.top()!=test[i]){
       balance.push(test[i]);
   }
   else{
    balance.pop();
   }
}
if(balance.size()==0){
  cout << "YES";
}
else{
    cout << "NO";
}
}