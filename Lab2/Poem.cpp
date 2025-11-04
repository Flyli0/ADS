#include <iostream>
using namespace std;

class Node{
    public:
    string val;
    Node* next;
    Node(string newVal){
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

    void append(string val){
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
};
    
void shift(LinkedList& a,int b){
    for(int i = 0; i<b; i++){
        string val = a.head -> val;
        a.append(val);
        a.pop();
    }
};

int main(){
    int n, sh;
    string a;
    cin >> n >> sh;
    LinkedList poem;
    for(int i = 0; i<n; i++){
        cin >> a;
        poem.append(a);
    }
    shift(poem,sh);
    poem.print();
}