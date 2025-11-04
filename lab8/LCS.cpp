#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 MOD = 1000000007LL;
const int64 P = 31LL;

int chtoi(char c) { return c - 'a' + 1; }

unordered_set<int64> all_sub_hashes(const string &s, int len, const vector<int64> &p_pow) {
    unordered_set<int64> res;
    int n = (int)s.size();
    if (len <= 0 || len > n) return res;

    vector<int64> h(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        h[i+1] = (h[i] * P + chtoi(s[i])) % MOD;
    }

    for (int l = 0; l + len <= n; ++l) {
        int r = l + len;
        int64 cur = (h[r] - (h[l] * p_pow[len]) % MOD + MOD) % MOD;
        res.insert(cur);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    if (!(cin >> K)) return 0;
    vector<string> ss(K);
    for (int i = 0; i < K; ++i) cin >> ss[i];

    int maxlen = 0;
    for (auto &s : ss) maxlen = max(maxlen, (int)s.size());

    vector<int64> p_pow(maxlen + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= maxlen; ++i) p_pow[i] = (p_pow[i-1] * P) % MOD;

    string answer = "";
    int low = 1, high = maxlen;
    while (low <= high) {
        int mid = (low + high) / 2;


        vector<unordered_set<int64>> sets;
        sets.reserve(K);
        for (int i = 0; i < K; ++i) sets.push_back(all_sub_hashes(ss[i], mid, p_pow));


        bool anyEmpty = false;
        for (auto &st : sets) if (st.empty()) { anyEmpty = true; break; }
        if (anyEmpty) {
            high = mid - 1;
            continue;
        }

        int idx_min = 0;
        for (int i = 1; i < K; ++i)
            if (sets[i].size() < sets[idx_min].size()) idx_min = i;

        bool found = false;
        int64 found_hash = -1;
        for (auto h : sets[idx_min]) {
            bool ok = true;
            for (int j = 0; j < K; ++j) if (j != idx_min) {
                if (! (sets[j].count(h)) ) { ok = false; break; }
            }
            if (ok) { found = true; found_hash = h; break; }
        }

        if (found) {

            vector<int64> h(ss[0].size() + 1, 0);
            for (int i = 0; i < (int)ss[0].size(); ++i) h[i+1] = (h[i] * P + chtoi(ss[0][i])) % MOD;

            bool placed = false;
            for (int l = 0; l + mid <= (int)ss[0].size(); ++l) {
                int r = l + mid;
                int64 cur = (h[r] - (h[l] * p_pow[mid]) % MOD + MOD) % MOD;
                if (cur == found_hash) {
                    answer = ss[0].substr(l, mid);
                    placed = true;
                    break;
                }
            }

            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
