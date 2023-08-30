//2023-08-29.
#include "bits/stdc++.h"

using namespace std;

int n, m;
int arr[10];

void func() {
    for (int i = m; i < n; i++) arr[i] = 1;
    do {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (next_permutation(arr, arr + n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func();
}
