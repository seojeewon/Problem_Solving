//2023-09-07.
#include "bits/stdc++.h"

using namespace std;
int k;
int board[15], arr[6];
bool vis[15];

void func(int r) {
    if (r == 6) {
        for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < k; i++) {
        if (vis[i]) continue;
        if(r>0&&arr[r-1]>board[i]) continue;
        arr[r] = board[i];
        vis[i] = 1;
        func(r + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        fill(vis, vis + 15, 0);
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> board[i];
        func(0);
        cout << '\n';
    }
}