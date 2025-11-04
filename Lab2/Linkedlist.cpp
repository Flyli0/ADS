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
        void print(){
            Node* temp = head;
            while(temp -> next){
                cout << temp -> val << ' ';
            temp = temp -> next;
            }   
        }
        Node* reverse(Node* head){
            if(!head || !(head -> next)){
                return head;
            }
            else{
                Node* newHead = reverse(head -> next);
                head -> next -> next = head;
                head ->next = nullptr;
                return newHead;
            }
        }
    };
int main(){
    int n; 
    cin >> n;
    LinkedList a;
    for(int i = 0; i<n; i++){
        a.append(i);
    }
    a.print();
}