//2023-08-29.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int board[10];
int arr[10];

void func() {
    for (int i = m; i < n; i++) arr[i] = 1;
    do {
        for (int i = 0; i < n; i++) {
            if (arr[i]) continue;
            cout << board[i] << ' ';
        }
        cout << '\n';
        reverse(board+m, board+n);
    } while (next_permutation(board, board + n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    sort(board, board + n);
    func();
}