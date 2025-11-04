#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long int n, q, val;
    long int l1, r1;
    long int l2, r2;
    long int c1 = 0, c2 = 0;
    cin >> n >> q;
    vector<int> array;
    for(int i = 0; i<n; i++){
        cin >> val;
        array.push_back(val);
    }
    long int querrys[q][4];
    for(long int i = 0; i<q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        querrys[i][0] = l1; 
        querrys[i][1] = r1;
        querrys[i][2] = l2;
        querrys[i][3] = r2;
    }
    sort(array.begin(), array.end());
    for( long int i = 0; i<q; i++){
        auto low1 = lower_bound(array.begin(),array.end(),querrys[i][0]);
        auto high1 = upper_bound(array.begin(),array.end(),querrys[i][1]);
        auto low2 = lower_bound(array.begin(),array.end(),querrys[i][2]);
        auto high2 = upper_bound(array.begin(),array.end(),querrys[i][3]);
        c1 = high1 - low1;
        c2 = high2 - low2;
        long int L = max(querrys[i][0], querrys[i][2]);
        long int R = min(querrys[i][1], querrys[i][3]);
        long int cinter = 0;
        if (L <= R) {
            auto leftI = lower_bound(array.begin(), array.end(), L);
            auto rightI = upper_bound(array.begin(), array.end(), R);
            cinter = rightI - leftI;
        }
    cout << c1 +  c2 - cinter << endl;
    }
}