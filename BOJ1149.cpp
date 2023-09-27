//2023-09-27.
#include "bits/stdc++.h"

using namespace std;
int n;  //집의 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<vector<int>> house(n + 1, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> house[i][j];
    }

    //초기화
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + house[i][2];
    }

    int ans = min(dp[n][0], dp[n][1]);
    ans = min(ans, dp[n][2]);
    cout << ans;
}