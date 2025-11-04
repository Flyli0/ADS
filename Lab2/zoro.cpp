#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
        Node* temp = head;
        if(p == 0 || head == nullptr){
            node -> next = head;
            head = node;
        }
        else{
            for(int i = 0; i<p-1; i++){
                temp = temp -> next;
            }     
            node -> next = temp -> next;
            temp -> next = node;
         }   
        return head;
};

 
Node* remove(Node* head, int p){
    if (!head) return nullptr;
    if (p == 0){
        Node* del = head;
        head = head->next;
        delete del;
        return head;
    }
    Node* temp = head;
    for (int i = 0; temp->next && i < p - 1; i++){
        temp = temp->next;
    }
    if (temp->next){
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
    return head;
}

 
Node* replace(Node* head, int p1, int p2){
    Node* posa = head ;
    Node* posaprev = nullptr;
    Node* posbprev = head;
    for(int i = 0; i<p1; i++){
        posaprev = posa;
        posa = posa -> next;
    }
    if(posaprev == nullptr){
        head = posa -> next;
    }
    else{
        posaprev -> next = posa -> next;
    }

    if (p2 == 0) {
        posa->next = head;
        head = posa;
        return head;
    }
    
    for(int j = 0; j<p2; j++){
        posbprev = posbprev -> next;
    }
    posa -> next = posbprev -> next;
    posbprev -> next = posa;
    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;

    while (cur){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}


 
void print(Node* head,string& ans){
    Node* temp = head;
    while(temp){
        ans += to_string(temp->val) + " ";
        temp = temp->next;
    }
    ans += "\n";
}
 
Node* cyclic_left(Node* head, int x){
    Node* temp = head;
    int c = 1;
    while(temp -> next){
        temp = temp -> next;
        c++;
    }
    x %= c;
    if (x == 0) return head;
    temp -> next = head;
    Node* newTail = head;
    for(int i = 0; i<x-1; i++){
        newTail = newTail -> next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
 
Node* cyclic_right(Node* head, int x){
    Node* temp = head;
    int c = 1;
    while(temp -> next){
        temp = temp -> next;
        c++;
    }
    x %= c;
    if (x == 0) return head;
    temp -> next = head;
    Node* newTail = head;
    for(int i = 0; i<c-x-1; i++){
        newTail = newTail -> next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;

}
 
int main(){
    string answer = "";
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head,answer);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    cout << answer;
    return 0;
}