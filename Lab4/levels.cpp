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

int height(Node* node) {
    if (node == nullptr) return 0;  
    return 1 + max(height(node->left), height(node->right));
}

vector<int> sumoflvl(Node* node){
    vector<int> sums;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty()){
        int size = q.size();
        int lvlsum = 0;

        for(int i = 0; i<size; i++){
            Node* cur = q.front();
            q.pop();

            lvlsum+= cur -> val;

            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right);
        }
        sums.push_back(lvlsum);  
    }
    return sums;
}

int main(){
    int n, m;
    cin >> n;
    BinSearchTree a;
    for(int i = 0; i<n; i++){
        cin >> m;
        a.insert(m);
    }
    cout << height(a.root) << endl;
    sumoflvl(a.root);
    for(const auto& it : sumoflvl(a.root)){
        cout << it << ' ';
    }
    
}