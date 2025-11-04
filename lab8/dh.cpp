#include <bits/stdc++.h>
using namespace std;


unordered_set<string> Substrings(string s)
{
    unordered_set<string> us;
    for (int i = 0; i < s.size(); ++i) {
        string ss = "";
        for (int j = i; j < s.size(); ++j) {

            ss = ss + s[j];
            us.insert(ss);
        }
    }
    return us;
}

int main()
{
    string str;
    cin >> str;
    cout << Substrings(str).size();
    return 0;
}