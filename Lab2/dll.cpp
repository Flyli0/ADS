#include <iostream>
#include <list>
using namespace std;

int main(){
string com, name, answer = "";
list<string> shelf;
    while(true){
        cin >> com;
        if(com == "add_front"){
            cin >> name;
            shelf.push_front(name);
            answer+="ok\n";
        }
        else if(com == "add_back"){
            cin >> name;
            shelf.push_back(name);
            answer+="ok\n";
        }
        else if(com == "front"){
            if(!shelf.empty()){
            answer+=shelf.front();
            answer+='\n';
            }
            else{
                answer+="error\n";
            }
        }
        else if(com == "back"){
            if(!shelf.empty()){
            answer+=shelf.back();
            answer+='\n';
            }
            else{
                answer+="error\n";
            }
        }
        else if(com == "erase_front"){
            if(!shelf.empty()){
            answer+=shelf.front();
            answer+='\n';
            shelf.pop_front();
            }
            else{
                answer+="error\n";
            }
        }
        else if(com == "erase_back"){
            if(!shelf.empty()){
            answer+=shelf.back();
            answer+='\n';
            shelf.pop_back();
            }
            else{
                answer+="error\n";
            }
        }
        else if(com == "clear"){
            shelf.clear();
            answer+="ok\n";
        }
        else if(com == "exit"){
            answer+="goodbye";
            break;
        }
    }
    cout << answer;
}