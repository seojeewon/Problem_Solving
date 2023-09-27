//2023-09-27.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> dp(n + 1, 0);
    vector<int> pre(n + 1, 0);
    dp[1] = 0;
    pre[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0) {
            if (dp[i / 2] + 1 < dp[i]) {
                dp[i] = dp[i / 2] + 1;
                pre[i] = i / 2;
            }
        }
        if (i % 3 == 0) {
            if (dp[i / 3] + 1 < dp[i]) {
                dp[i] = dp[i / 3] + 1;
                pre[i] = i / 3;
            }
        }
    }
    cout << dp[n] << '\n' << n << ' ';
    int k = n;
    while (k != 1) {
        cout << pre[k] << ' ';
        k = pre[k];
    }
}