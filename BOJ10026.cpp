//2023-08-22.
#include "bits/stdc++.h"

using namespace std;

string board[102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void initVis() {
    for (int i = 0; i < 102; i++)
        fill(vis[i], vis[i] + 102, false);
}

int bfs(queue<pair<int, int>> &q, int n, int cnt, char color) {
    initVis();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] != color) continue;
            vis[i][j] = true;
            cnt++;
            q.push({i, j});
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != color) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cntBlue = 0, cntRed = 0, cntGreen = 0, cntRG = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    queue<pair<int, int>> B;
    queue<pair<int, int>> R;
    queue<pair<int, int>> G;
    queue<pair<int, int>> RG;
    cntBlue = bfs(B, n, cntBlue, 'B');
    cntRed = bfs(R, n, cntRed, 'R');
    cntGreen = bfs(G, n, cntGreen, 'G');
    //Red+Green
    initVis();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] == 'B') continue;
            vis[i][j] = true;
            cntRG++;
            RG.push({i, j});
            while (!RG.empty()) {
                auto cur = RG.front();
                RG.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] == 'B') continue;
                    vis[nx][ny] = true;
                    RG.push({nx, ny});
                }
            }
        }
    }

    cout << cntBlue + cntRed + cntGreen << ' ' << cntBlue + cntRG;
}