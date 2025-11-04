#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string to_lowercase(const string &s) {
    string res = s;
    for (auto &ch : res)
        ch = tolower(ch);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string prev;
    int n;
    cin >> prev >> n;
    prev = to_lowercase(prev);

    vector<string> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i];

    int best = 0;
    vector<string> result;

    for (auto &city : cities) {
        string city_lower = to_lowercase(city);

        string combined = prev + "#" + city_lower;
        vector<int> pi = prefix_function(combined);

        int overlap = pi.back(); 
        if (overlap > best) {
            best = overlap;
            result = {city};
        } else if (overlap == best) {
            result.push_back(city);
        }
    }

    cout << result.size() << "\n";
    for (auto &name : result)
        cout << name << "\n";
}
