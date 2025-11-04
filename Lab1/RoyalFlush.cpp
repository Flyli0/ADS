#include <iostream>
#include <deque>
using namespace std;
int main(){
deque<int> deck;
int n;
int sizze;
deque<int>::iterator point = deck.begin();
cin >> n;
int sizes[n];
for(int i = 0; i < n; i++){
    cin >> sizze;
    sizes[i] = sizze;
    }
for(int i = 0; i<n; i++){
    for(int j = sizes[i]; j>0; j--){
        deck.push_front(j);
            for(int k = 0; k<j; k++){
                deck.push_front(deck.back());
                deck.pop_back();
            }
         }
     for(int e = 0; e<sizes[i]; e++){
        cout << deck.front() << ' ';
        deck.pop_front();
         }      
    cout << endl;  
    }

}