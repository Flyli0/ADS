#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue{
    private:
    vector<long long int> heap;
    public:
    long long int parent(long long int i){ return (i-1)/2; };
    long long int left(long long int i){return 2*i+1;}
    long long int right(long long int i){return 2*i+2;}

    void swap(long long int i,long long int j){
        long long int temp;
        temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void print(){
        for(const auto& it: heap){
            cout << it << ' ';
        }
    }
    void heapifyUp(long long int i){
        while(i>0){
            long long int parent = this -> parent(i);
            if(heap[i] < heap[parent]){
                swap(i,parent);
                i = parent;
            }
            else{
                break;
            }
        }
    }
    
    void heapifyDown(long long int i){
        long long int u = heap.size();
        while(true){
            long long int l = this -> left(i);
            long long int r = this -> right(i);
            long long int smallest = i;
            if(l<u && heap[l]<heap[smallest]){
                smallest = l;
            }
            if(r<u && heap[r] < heap[smallest]){
                smallest = r;
            }
            if(i!= smallest){
                swap(i,smallest);
                i = smallest;
            }
            else{
                break;
            }
        }
    }

    void pop(){
        long long int n = heap.size();
        swap(0,n-1);
        heap.pop_back();
        heapifyDown(0);
    }

    long long int top(){
        return heap[0];
    }

    long long int sizze(){
        return heap.size();
    }

    void insert(long long int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
};

int main(){
    long long int n;
    MaxPriorityQueue a;
    cin >> n;
    for(int i = 0; i<n; i++){
        long long int m;
        cin >> m;
        a.insert(m);
    }
  long long int cost = 0;
  while(a.sizze()>1){
    long long int first;
    long long int second;
    first = a.top();
    a.pop();
    second = a.top();
    a.pop();
    a.insert(first+second);
    cost += first+second;
  }
  cout << cost;
}