//2023-09-07.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max = -1, t, index = -1;
    for (int i = 0; i < 9; i++) {
        cin >> t;
        if (t > max) {
            max = t;
            index = i + 1;
        }
    }
    cout << max << '\n' << index;
}
