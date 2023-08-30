//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
string kInt[100002];
map<string, int> kStr;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        kInt[i + 1] = s;
        kStr[s] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s[0] >= '1' && s[0] <= '9') {
            int idx = stoi(s);
            cout << kInt[idx] << '\n';
        } else {
            cout << kStr[s] << '\n';
        }
    }
}