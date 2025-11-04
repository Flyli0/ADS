#include <iostream>
#include <cmath>
#include <forward_list>
using namespace std;

/*class Node{
    public:
    int val;
    Node* next;
    Node(int newVal){
        val = newVal;
        next = nullptr;
    }
};

class LinkedList{
    public:

    Node* head;
    LinkedList(){
        head = nullptr;
    }

    void append(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }

    void pop(){
        if(!head){
            throw runtime_error("You deleting from an empty list?))");
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    void print(){
        Node* temp = head;
        while(temp -> next){
            cout << temp -> val << ' ';
            temp = temp -> next;
        }
        cout << temp -> val;
    }
    void insert(int val, int pos){
        Node* temp = head;
        Node* newNode = new Node(val);
        if(pos == 0){
            newNode -> next = head;
            newNode = head;
        }
        for(int i = 0; i<pos-1; i++){
            temp = temp -> next;
        }     
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
};
*/

        


int main(){
    int n, val, neww, m;
    forward_list<int> a;
    cin >> n;
    forward_list<int>::iterator it = a.before_begin();
    for(int i=0; i<n; i++){
        cin >> val;
        it = a.insert_after(it,val);
    }
    auto pos = a.before_begin();
    cin >> neww >> m;
    for(int i = 0; i<m; i++){
        pos++;
    }
    a.insert_after(pos,neww);
    for(auto& el:a){
        cout << el << ' ';
    }
}