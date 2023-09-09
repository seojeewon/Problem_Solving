//2023-09-08.
#include "bits/stdc++.h"

using namespace std;
int n, white, blue;
int board[130][130];

bool check(int k, int x, int y) {
    bool isBlue = board[x][y];
    for (int i = x; i < x + k; i++)
        for (int j = y; j < y + k; j++) {
            if (board[i][j] != isBlue) return false;
        }
    return true;
}

void func(int k, int x, int y) {
    if (k == 1) {
        if (board[x][y]) blue++;
        else white++;
        return;
    }
    if (check(k, x, y)) {
        if (board[x][y]) blue++;
        else white++;
        return;
    }
    func(k / 2, x, y);
    func(k / 2, x + k / 2, y);
    func(k / 2, x, y + k / 2);
    func(k / 2, x + k / 2, y + k / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    func(n, 0, 0);
    cout << white << '\n' << blue;
}