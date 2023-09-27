//2023-09-27.
#include "bits/stdc++.h"

using namespace std;
int n;
int arr[502][502];
int dp[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    //초기화
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + arr[i][1];
        dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
        for (int j = 2; j < i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }
    int maximum = -1;
    for (int i = 1; i <= n; i++)
        maximum = max(maximum, dp[n][i]);
    cout << maximum;
}