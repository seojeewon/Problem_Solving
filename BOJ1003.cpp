//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
pair<int, int> board[41];
int t;

void func() {
    for (int i = 2; i < 41; i++) {
        board[i] = {board[i - 1].first + board[i - 2].first, board[i - 1].second + board[i - 2].second};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    board[0] = {1, 0};
    board[1] = {0, 1};
    func();
    while (t--) {
        int idx;
        cin >> idx;
        cout << board[idx].first << ' ' << board[idx].second << '\n';
    }
}
