//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int n, k;    //수빈, 동생 위치
int loc[100011];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(loc, loc + 100010, -1);  //초기화
    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }
    queue<int> Q;
    loc[n] = 0;
    Q.push(n);
    while (loc[k] == -1) {
        int cur = Q.front();
        Q.pop();
        for (int nx: {cur * 2, cur - 1, cur + 1}) {
            if (nx < 0 || nx > 100010) continue;
            if (loc[nx] != -1) continue;
            if (nx == cur * 2) {
                loc[nx] = loc[cur];
                Q.push(nx);
            } else {
                loc[nx] = loc[cur] + 1;
                Q.push(nx);
            }
        }
    }
    cout << loc[k];
}