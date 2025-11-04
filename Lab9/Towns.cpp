#include <iostream>
#include <vector>

using namespace std;

vector<long long> lps(string& str){
    long long i = 1;
    long long n = str.size();
    long long len = 0;

    vector<long long> lps(n,0);

    while(i<n){
        if(str[len] == str[i]){
            len++;
            lps[i]= len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;    
            }
            else{
                len = lps[len-1];
            }
        }
    } 
    return lps;
}

int main() {

    string       prev;
    long long    n;
    long long    maxx = 0;

    cin >> prev >> n;
    prev[0] = tolower(prev[0]);

    vector<string> cities;
    vector<string> answer;
    

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        cities.push_back(temp);
    }   

    for(auto& city: cities){
        string temp = city;
        temp[0] = tolower(temp[0]);
        string test = temp + '#' + prev;
        vector<long long> ps = lps(test);
        
        if(ps.back() > maxx & ps.back()!=0){
            answer = {city};
            maxx = ps.back();
        }
        else if(ps.back() == maxx && ps.back()!=0){
            answer.push_back(city);
        }

        
    }
    cout << answer.size() << endl;
    for(auto& l:answer){
        cout << l << endl;
    }
}
