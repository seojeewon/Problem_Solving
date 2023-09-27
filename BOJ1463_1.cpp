//2023-09-27.
#include "bits/stdc++.h"

using namespace std;
int n;
int dp[1000002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[n];
}
