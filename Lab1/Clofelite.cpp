#include <iostream>
#include <queue>
using namespace std;
int main(){
 int n;
 string S;
 queue<int> KQ;
 queue<int> SQ;
 cin >> n;
 cin >> S;
 for(int i = 0; i < n; i++){
    if(S[i] == 'K'){
        KQ.push(i);
    }
    else{
        SQ.push(i);
    }
 }
while(!SQ.empty() && !KQ.empty()){
    if(SQ.front() < KQ.front()){
        SQ.push(SQ.front()+n);
    }
    else{
        KQ.push(KQ.front()+n);
    }
    KQ.pop();
    SQ.pop();
 }
if(!KQ.empty()){
    cout << "KATSURAGI";
}
else{
    cout << "SAKAYANAGI";
}
}