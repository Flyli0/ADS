#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(){
char sign;
int num;
deque<int> test;
vector<int> answer;
while(sign != '!'){
    cin >> sign;
    if(sign == '+'){
        cin >> num;
        test.push_front(num);
    }
    else if(sign == '-'){
        cin >> num;
        test.push_back(num);
    }
    else if(sign == '+'){
        cin >> num;
        test.push_front(num);
    }
    if(sign == '*'){
        if(!test.empty() && test.size()!=1){
        answer.push_back(test.front()+test.back());
        test.pop_back();
        test.pop_front();
       }
        else if(test.size()==1){
            answer.push_back(test.front()*2);
            test.pop_front();
        }
        else{
        answer.push_back(-1);
       }
    }
  }
for(const auto &i: answer){
    if(i!=-1){
        cout << i << endl; 
    }
    else{
        cout << "error" << endl;
    }
}
}
