#include <iostream> 

using namespace std;

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
    private:
    Node* root;
    public:
    BinSearchTree(){
        root = nullptr;
    }

    void insert(int newval){
        insert(newval,root);
    }

    void inorder(){
        inorder(root);
    }
    void preorder(){
        preorder(root);
    }
    void postorder(){
        postorder(root);
    }

    Node* find(int findval){
        return find(findval,root);
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

    void inorder(Node* node){
        if(!node){
            return;
        }
        inorder(node -> left);
        cout << node -> val;
        inorder(node -> right);
    }

    void preorder(Node* node){
        if(!node){
            return;
        }
        cout << node -> val;
        preorder(node -> left);
        preorder(node -> right);
    }

    void postorder(Node* node){
        if(!node){
            return;
        }
        postorder(node -> left);
        postorder(node -> right);
        cout << node -> val;
    }

    Node* find(int val, Node* node){
        if(!node) return nullptr;       
        if(val == node -> val){
            return node;
        }
        else if(val > node -> val){
            return find(val,node->right);
        }
        else if(val < node -> val){
            return find(val,node -> left);
        }
        return nullptr;
    }
   
    
};

void Preoorder(Node* node){
        if(!node){
            return;
        }
        cout << node -> val << ' ';
        Preoorder(node -> left);        
        Preoorder(node -> right);
    }
    
void subtreePreorder(int val, BinSearchTree& tree){
        Node* a = tree.find(val);
        Preoorder(a);
    }

int main(){
    int n, m;
    cin >> n;
    BinSearchTree a;
    for(int i = 0; i<n; i++){
        cin >> m;
        a.insert(m);
    }
    cin >> m;
    subtreePreorder(m,a);
}