//2023-09-07.
#include "bits/stdc++.h"

using namespace std;
int m, n, k, board[110][110];
bool vis[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    //board에 직사각형 표시
    int x1, y1, x2, y2;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = m - y2; j < m - y1; j++) {
            for (int l = x1; l < x2; l++)
                board[j][l] = 1;
        }
    }

    queue<pair<int, int>> Q;
    int num = 0;
    vector<int> area;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j]) continue;
            vis[i][j] = 1;
            num++;
            Q.push({i, j});
            int a = 0;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                a++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            area.push_back(a);
        }
    }

    cout << num << '\n';
    sort(area.begin(), area.end());
    for (int i = 0; i < num; i++) cout << area[i] << ' ';
}