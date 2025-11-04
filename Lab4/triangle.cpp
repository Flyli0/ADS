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

    void inorder(){
        inorder(root);
    }
    void preorder(){
        preorder(root);
    }
    void postorder(){
        postorder(root);
    }

    bool find(int findval){
        return find(findval,root);
    }

    void remove(int val){
        Node* node = root;
        remove(val,node);
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

    bool find(int val, Node* node){
        if(!node) return false;       
        if(val == node -> val){
            return true;
        }
        else if(val > node -> val){
            return find(val,node->right);
        }
        else if(val < node -> val){
            return find(val,node -> left);
        }
        return false;
    }

    Node* Successor(Node* node){
        node = node -> right;
        while(node != nullptr && node->left!=nullptr){
            node = node -> left;
        }
        return node;
    }

    Node* remove(int val, Node*& node){
        if(root == nullptr){
            return root;
        }

        if(val > node -> val){
            node -> right = remove(val,node->right);
        }
        else if(val < node -> val){
            node -> left = remove(val,node -> left);
        }
        else{

            if(node -> left == nullptr){
                Node* temp = node -> right;
                delete node;
                return temp;
             }
             
             if(node -> right == nullptr){
                Node* temp = node -> left;
                delete node;
                return temp;
             }

             Node* suc = Successor(node);
             node -> val = suc -> val;
             node -> right = remove(suc -> val, node -> right);
        }
        return node;
    }
};

int trianglecount(Node* a){
    Node* rt = a;
    int count = 0;
    if(a == nullptr){
       return 0;
    }
    if(rt -> left != nullptr && rt -> right != nullptr){
        count = 1;
    }
    return count + trianglecount(rt -> left) + trianglecount(rt -> right);
    
}
int main(){
    int n, m;
    cin >> n;
    BinSearchTree a;
    for(int i = 0; i<n; i++){
        cin >> m;
        a.insert(m);
    }
    cout << trianglecount(a.root);
}