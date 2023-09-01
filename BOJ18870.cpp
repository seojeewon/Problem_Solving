//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
map<int, int> M;
int n, idx = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> t = v;
    sort(t.begin(), t.end());
    for (int c: t) {
        if (!M[c]) M[c] = idx++;
    }

    for (int c: v) {
        cout << M[c] - 1 << ' ';
    }
}