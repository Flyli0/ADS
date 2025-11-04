#include <iostream>
#include <vector>
#include <string> 

using namespace std;

bool check(pair<string,pair<string,string>> s, pair<string,pair<string,string>> pivot){
    if(stoi(s.second.second) < stoi(pivot.second.second))
        return true;
    else if(stoi(s.second.second) == stoi(pivot.second.second) &&
            stoi(s.second.first) < stoi(pivot.second.first))
        return true;
    else if(stoi(s.second.second) == stoi(pivot.second.second) &&
            stoi(s.second.first) == stoi(pivot.second.first) &&
            stoi(s.first) <= stoi(pivot.first))
        return true;
    return false;
}

int partition(vector<pair<string,pair<string,string>>>& a , int low, int high){
    pair<string,pair<string,string>> pivot = a[high];
    int i = low - 1;

    for(int j = low; j<high; ++j){
        if(check(a[j],pivot)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(vector<pair<string,pair<string,string>>>& a , int low, int high){
    if(low < high){
        int pivot = partition(a,low, high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}

int main(){
    int n;
    string date; 
    cin >> n;
    vector<pair<string,pair<string,string>>> a;

    for(int i = 0; i<n; i++){

        string day,month,year;
        cin >> date;

        day = date.substr(0,2);
        month = date.substr(3,2);
        year = date.substr(6,4);

        pair<string,pair<string,string>> val = {day,{month,year}};
        a.push_back(val);
    }

    quicksort(a,0,a.size()-1);
    for(const auto& it : a){
        cout << it.first << '-' << it.second.first << '-' << it.second.second << endl;
    }
}