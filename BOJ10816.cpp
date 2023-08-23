//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
const int NUM = 1e7;
int board[20000008];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        board[tmp + NUM]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        cout << board[tmp + NUM] << ' ';
    }
}