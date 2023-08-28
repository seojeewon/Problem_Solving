//2023-08-26.
#include "bits/stdc++.h"

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (k == 0 || (i > arr[k - 1] && !isUsed[i])) {
            arr[k] = i;
            isUsed[k] = 1;
            func(k + 1);
            isUsed[k] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}