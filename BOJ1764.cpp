//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
map<string, bool> names;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> s;
        names[s] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (names[s])
            v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (string a: v)
        cout << a << '\n';
}