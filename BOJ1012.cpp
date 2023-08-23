//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < 52; i++) {
        fill(board[i], board[i] + 52, 0);
        fill(vis[i], vis[i] + 52, false);
    }
}

int bfs(queue<pair<int, int>> &Q, int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || !board[i][j]) continue;
            vis[i][j] = true;
            Q.push({i, j});
            ans++;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, k, x, y;
    cin >> T;

    while (T--) {
        init();
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x]++;
        }
        queue<pair<int, int>> Q;
        cout << bfs(Q, n, m) << '\n';
    }
}
