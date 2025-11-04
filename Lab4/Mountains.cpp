#include <iostream> 
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int val;
    Node(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class BinSearchTree{
    public:
    Node* root;
    public:
    BinSearchTree(){
        root = nullptr;
    }

    void insert(int newval){
        insert(newval,root);
    }

    private:
    void insert(int newval, Node*& curNode){
       if(!curNode){
            curNode = new Node(newval);
       }
       else if(curNode -> val > newval){
            insert(newval, curNode -> left);
       }
       else if(curNode -> val < newval){
            insert(newval, curNode -> right);
       }
    }

  
};

int main(){
    int m, n;
    
    string answer = "";
    BinSearchTree root;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int val;
        cin >> val;
        root.insert(val);
    }
    for(int i = 0; i<m; i++){
        Node* temp = root.root;
        bool check = true;
        string way;
        cin >> way;
        for(int j = 0; j<way.length(); j++){
            if(temp==nullptr){
                check = false;
                break;
            }
            if(way[j]=='R'){
                temp = temp->right;
            }
            else{
                temp = temp ->left;
            }
        }
        if(temp==nullptr){
            check = false;
        }
        if(check)answer += "YES\n";
        else answer += "NO\n";

    }
    cout << answer;
}