//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int board[1000002];
int n;

void func() {
    queue<int> Q;
    Q.push(1);
    while (board[n] == 0) {
        int cur = Q.front();
        Q.pop();
        for (int nx: {cur + 1, cur * 2, cur * 3}) {
            if (nx > 1000001) continue;
            if (board[nx]) continue;
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    func();
    cout << board[n];
}