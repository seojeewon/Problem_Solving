//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
ll dp[1001];
int n;

void func() {
    dp[1] = 1l, dp[2] = 3l;
    for (int i = 3; i < 1001; i++)
        dp[i] = (dp[i - 1] % 10007 + dp[i - 2] * 2 % 10007) % 10007;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func();
    cout << dp[n];

}