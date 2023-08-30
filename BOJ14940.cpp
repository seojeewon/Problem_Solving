//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) dist[i][j] = 0;
            else if (board[i][j] == 2) {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] == 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }

}
