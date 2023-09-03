//2023-09-02.
#include "bits/stdc++.h"

using namespace std;
int n, m;
map<long long, bool> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        M[t]=true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (M[t]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
