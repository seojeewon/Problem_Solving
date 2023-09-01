//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
int n, k, ans;
int coin[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    while (k != 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (k < coin[i]) continue;
            ans += k / coin[i];
            k %= coin[i];
        }
    }
    cout << ans;
}