//2023-09-18.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 7, tmp = 0, minN = 1000, sum = 0;
    while (t--) {
        cin >> tmp;
        if (tmp % 2 == 0) continue;
        sum += tmp;
        minN = min(minN, tmp);
    }
    if (minN == 1000) {
        cout << -1;
        return 0;
    }
    cout << sum << '\n' << minN;
}