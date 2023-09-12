//2023-09-12.
#include "bits/stdc++.h"

using namespace std;
using ll = long long;
int n;
map<ll, int> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll tmp = 0l;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        M[tmp]++;
    }
    int maximum = M.begin()->second;
    ll ans = M.begin()->first;
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        if (iter->second >= maximum) {
            if (iter->second == maximum) ans = min(ans, iter->first);
            else {
                maximum = iter->second;
                ans = iter->first;
            }
        }
    }

    cout << ans;
}