//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
int num[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        num[idx]++;
    }


    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < num[i]; j++)
            cout << i << '\n';
    }
}