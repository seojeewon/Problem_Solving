//2023-09-07.
#include "bits/stdc++.h"

using namespace std;
int n, x, ans;
int board[1000003];

int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        board[t] = 1;
    }
    cin >> x;
    for (int i = 1; i <= (x-1) / 2; i++) {
        if(x-i>1000000) continue;
        if (board[i] && board[x - i]) {
            ans++;
        }
    }
    cout << ans;

}
