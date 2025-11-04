#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main(){
    deque<int> Boris;
    deque<int> Nursik;
    int count = 0;
    int card;
    for(int i = 0; i<5; i++){
        cin >> card;
        Boris.push_back(card);
    }
    for(int i = 0; i<5; i++){
        cin >> card;
        Nursik.push_back(card);
    }
    while(!Boris.empty() && !Nursik.empty() && count<1000000){
        if(Boris.front() == 9 && Nursik.front()==0){
            Nursik.push_back(Boris.front());
            Nursik.push_back(Nursik.front());
        }
        else if(Boris.front() == 0 && Nursik.front()==9){
            Boris.push_back(Boris.front());
            Boris.push_back(Nursik.front());
        }
        else if(Boris.front()>Nursik.front()){
            Boris.push_back(Boris.front());
            Boris.push_back(Nursik.front());
        }
        else if(Boris.front()<Nursik.front()){
            Nursik.push_back(Boris.front());
            Nursik.push_back(Nursik.front());
        }
        Boris.pop_front();
        Nursik.pop_front();
        count++;
    }
    if(Boris.empty()){
        cout << "Nursik " << count;
    }
    else if(Nursik.empty()){
        cout << "Boris " << count;
    }
    else{
        cout << "blin nichya";
    }
}