//2023-09-28.
//dp[k]=k번째까지 합이 가장 큰 증가하는 부분 수열
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}