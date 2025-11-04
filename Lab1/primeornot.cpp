#include <iostream>
using namespace std;
int main(){
 int n,b=0;
 cin >> n;
int i = n;
if(n == 0 || n == 1){
    cout << "NO";}
else{
  for(int j=1 ; j<=i ;j++){
    if(i%j==0){
    b++;
    }
  if(b>2){
    cout<< "NO";
    break;
  }
  }
  if(b==2){
    cout << "YES" << endl;
  }
  b=0;
}
}
