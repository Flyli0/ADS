#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


long long int binarysearch(vector<long long int>& a,long long int linenum){
    long long int l = 1, r = a.size() - 1, mid = 0;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(linenum <= a[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main(){
   long long int n,m;
   string answer = "";
   long long int num;
   vector<long long int> borders;
   vector<long long int> lines;
   borders.push_back(0);
   cin >> n >> m;
   for(long long int i = 0; i < n; i++){
        cin >> num;
        borders.push_back(num+borders.back());
   }
   for(long long int i = 0; i<m; i++){
        cin >> num;
        answer+=to_string(binarysearch(borders,num));
        answer+='\n';
   }
   cout << answer;
}