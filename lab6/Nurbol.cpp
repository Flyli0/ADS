#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> old_to_new;
    map<string, string> new_to_old;

    for (int i = 0; i < n; ++i) {
        string old_nick, new_nick;
        cin >> old_nick >> new_nick;

        if (new_to_old.find(old_nick) != new_to_old.end()) {
            string original = new_to_old[old_nick];
            old_to_new[original] = new_nick;
            new_to_old.erase(old_nick);
            new_to_old[new_nick] = original;
        } else {
            old_to_new[old_nick] = new_nick;
            new_to_old[new_nick] = old_nick;
        }
    }

    vector<pair<string, string>> result;
    for (auto &pair : new_to_old) {
        result.push_back({pair.second, pair.first});
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for (auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}