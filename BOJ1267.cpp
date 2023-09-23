//2023-09-22.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    int Y = 0, M = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        Y = Y + (v[i] / 30 + 1) * 10;
        M = M + (v[i] / 60 + 1) * 15;
    }
    if (Y < M) {
        cout << "Y " << Y;
    } else if (M < Y) {
        cout << "M " << M;
    } else {
        cout << "Y M " << Y;
    }

}