#include <iostream>
#include <forward_list>
using namespace std;

int main(){
    forward_list<int> stream;
    int n,val;
    cin >> n;
    auto it = stream.before_begin();
    for(int i = 0; i<n; i++){
        cin >> val;
        if(i%2==0 || i == 0){
        it = stream.insert_after(it,val);
        }
    }
    while(!stream.empty()){
        cout << stream.front() << ' ';
        stream.pop_front();
    }
}