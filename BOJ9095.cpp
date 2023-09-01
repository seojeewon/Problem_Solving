//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
int t, n;
int board[11];

void func() {
    board[1] = 1, board[2] = 2, board[3] = 4;
    for (int i = 4; i < 11; i++)
        board[i] = board[i - 1] + board[i - 2] + board[i - 3];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    func();
    while (t--) {
        cin >> n;
        cout << board[n] << '\n';
    }
}