#include <iostream> 
#include <vector>
#include <cmath>
#include <queue>

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

    Node* find(int val,Node* root ) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        if (cur->val == val) return cur;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return nullptr;
}
   
    
};

int height(Node* node) {
    if (node == nullptr) return 0;  
    return 1 + max(height(node->left), height(node->right));
}

int width(Node* node){
    
    queue<Node*> q;
    q.push(node);
    int count = 1;
    while(!q.empty()){
        int sz = q.size();
        count = max(sz,count);
        for(int i = 0; i<sz; i++){
            Node* cur = q.front();
            q.pop();
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right);
        }
          
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int x,y,z;
    BinSearchTree a;
    a.root = new Node(1);
    for(int i = 1; i<n; i++){
        cin >> x >> y >> z;
        Node* node = new Node(y);
            if(z == 0){
                a.find(x)->left = node;
            }
            else if(z == 1){
                a.find(x)->right = node;
            
        }
    }
    cout << width(a.root);
}