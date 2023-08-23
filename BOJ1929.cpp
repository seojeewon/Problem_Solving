//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
bool num[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    fill(num, num + 1000001, true);
    num[1] = false;
    for (ll i = 2; i < 1000001; i++) {
        if (!num[i]) continue;
        for (int j = i; j * i < 1000001; j++) {
            num[i * j] = false;
        }
    }
    for (int i = m; i <= n; i++) {
        if (num[i])
            cout << i << '\n';
    }


}

