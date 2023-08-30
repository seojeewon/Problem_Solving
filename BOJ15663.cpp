//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int v[10];
int arr[10];

void func() {
    for (int i = m; i < n; i++) arr[i] = 1;
    do {
        for (int i = 0; i < n; i++) {
            if (!arr[i]) cout << v[i] << ' ';
        }
        cout << '\n';
        reverse(v + m, v + n);
    } while (next_permutation(v, v + n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    func();
}