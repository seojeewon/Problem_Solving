//2023-09-27.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int arr[100005];
int dp[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    while (m--) {
        int i, j;
        cin >> i >> j;
        if (i == 1) {
            cout << dp[j] << '\n';
        } else {
            cout << dp[j] - dp[i - 1] << '\n';
        }
    }
}