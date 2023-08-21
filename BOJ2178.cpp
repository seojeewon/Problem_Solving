//2023-08-21.

#include "bits/stdc++.h"

#define X first
#define Y second

using namespace std;

int board[102][102];    //미로판
int vis[102][102];  //최소거리
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    queue<pair<int, int>> Q;
    cin >> n >> m;
    string s[n];

    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = s[i][j] - '0';

    vis[0][0] = 1;    //방문(거리)표시
    Q.push({0, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!vis[nx][ny] && board[nx][ny]) {
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }


    cout << vis[n - 1][m - 1];
}