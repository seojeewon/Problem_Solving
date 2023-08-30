//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int h, n, m, ans;
int board[102][102][102];
int dist[102][102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int, int, int>> Q;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            fill(dist[i][j], dist[i][j] + 102, -1);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    dist[i][j][k] = 0;
                    Q.push({i, j, k});
                }

            }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        ans = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)];
        for (int dir = 0; dir < 4; dir++) {
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[get<0>(cur)][nx][ny] != -1 || board[get<0>(cur)][nx][ny] == -1) continue;
            dist[get<0>(cur)][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({get<0>(cur), nx, ny});
        }
        for (int dir = 0; dir < 2; dir++) {
            int nz = get<0>(cur) + dz[dir];
            if (nz < 0 || nz >= h) continue;
            if (dist[nz][get<1>(cur)][get<2>(cur)] != -1 || board[nz][get<1>(cur)][get<2>(cur)] == -1) continue;
            dist[nz][get<1>(cur)][get<2>(cur)] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz, get<1>(cur), get<2>(cur)});
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++) {
                if (board[i][j][k] == 0 && dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }
            }

    cout << ans;

}