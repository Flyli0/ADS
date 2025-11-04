#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<int> freq(26, 0);
        queue<char> q;
        string ans;
        for (int i = 0; i < N; ++i) {
            char c; cin >> c;
            freq[c - 'a']++;
            q.push(c);
            while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();

            if (q.empty()) ans += "-1 ";
            else {
                ans.push_back(q.front());
                ans.push_back(' ');
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
