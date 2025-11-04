#include <iostream>
#include <vector>

using namespace std;

string decode(vector<long long>& ImKindaTired){
    string answer = "";
    int p         = 2;

    vector<long long> p_power(ImKindaTired.size());
    p_power[0] = 1;

    for(long long i = 1; i<ImKindaTired.size(); i++){
        p_power[i] = (p_power[i-1]*p);
    }

    answer += char((ImKindaTired[0]/p_power[0]) + 97);
    for(long long i = 1; i<ImKindaTired.size(); i++){
        long long diff = ImKindaTired[i] - ImKindaTired[i-1];
        long long power =  1LL << i;
        char c = char(diff/power + 97);
        answer+=c;
    }
    return answer;
}

int main(){
    vector<long long> hash;
    int n; 
    cin >> n; 
    for(long long int i = 0; i<n; i++){
        long long int val;
        cin >> val;
        hash.push_back(val);
    }
    cout << decode(hash);
}