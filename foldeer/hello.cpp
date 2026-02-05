#include<iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; string s;
        cin >> n >> s;

        array<int,26> cnt{};
        for (char c : s) cnt[c - 'a']++;

        int mx = 0;
        for (int i = 1; i < 26; ++i) if (cnt[i] > cnt[mx]) mx = i;

        if (cnt[mx] == n) {
            // all same, do nothing (operation with i = j)
            cout << s << '\n';
            continue;
        }

        char best = char('a' + mx);
        for (int i = 0; i < n; ++i) {
            if (s[i] != best) { s[i] = best; break; }
        }
        cout << s << '\n';
    }
    return 0;
}