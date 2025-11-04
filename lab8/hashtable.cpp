#include <iostream>
#include <vector>
#include <list>

using namespace std;

class ht{
    private:

    vector<list<pair<string,int>>>   table;
    list<pair<string,int>>::iterator it;

    int capacity;
    int elCounter;
    double threshold;

    int hash(string& key){
        unsigned long Hashs = 0;
        for(const auto& it: key){
            Hashs = Hashs*31+it;        }
        return Hashs % this -> capacity;
    }

    double load_factor(){
        return this->elCounter/this->capacity;
    }

    void resize_table(){
        int oldSize = this -> capacity;
        int newSize = this -> capacity * 2;

        this -> capacity = newSize;
        
        vector<list<pair<string,int>>> newTable(this->capacity);

        for(int i = 0; i<table.size(); i++){
            for(it = table[i].begin(); it!=table[i].end(); it++){
                int newIndex = hash(it -> first);
                newTable[newIndex].push_back(make_pair(it->first, it->second));
            }
        }
        table = newTable;
    }

    public:
    
    ht(int cap, double treshold = 0.75){
        this -> capacity = cap;
        table.resize(this->capacity);
        this -> threshold = treshold;
        elCounter = 0;
    }

    void insert(string key,int val){
        if(load_factor() > threshold){
            resize_table();
        }

        int index = hash(key);

        for(it = table[index].begin(); it!=table[index].end();++it){
            if(it->first == key){
                it->second = val;
                return;
            }
        }
        table[index].push_back(make_pair(key,val));
        elCounter++;
    }

    void remove(string key){
        int remhash = hash(key);
        for(it = table[remhash].begin(); it!=table[remhash].end();++it){
            if(it -> first == key){
                table[remhash].erase(it);
                return;
            }
        }
    }

    int search(string key) {
    int index = hash(key);
    for (auto& it : table[index]) {
        if (it.first == key)
            return it.second;
        }
    return -1;
    }
};

int main(){

}