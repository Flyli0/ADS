#include <iostream>
using namespace std;
 
class Node{

    public:
    int val;
    Node* next;
    Node(int newVal){

        next = nullptr;
        val = newVal;
    }
};

class Linkedlist{
    
    public:
    Node* head;
    Linkedlist(){

        head = nullptr;
    }
    void append(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
        }
        else{
            Node* temp;
            temp = head;
            while(temp -> next){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    void print(){
        Node* temp = head;
        while(temp -> next){
            cout << temp << '=>'; 
            temp = temp -> next;
        }
    }
    void pop(){
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
};
