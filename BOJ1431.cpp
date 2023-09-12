//2023-09-12.
#include "bits/stdc++.h"

using namespace std;
int n;

int check(string &s) {
    int ans = 0;
    for (char c: s) {
        if (c >= '0' && c <= '9') ans += c - '0';
    }
    return ans;
}

bool cmp(string &s1, string &s2) {
    if (s1.size() == s2.size()) {
        if (check(s1) == check(s2)) {
            return s1 < s2;
        }
        return check(s1) < check(s2);
    }
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (string s: v) cout << s << '\n';
}
