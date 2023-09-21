//2023-09-15.
#include "bits/stdc++.h"

using namespace std;
int n, ans = 0;
bool h[101];
int board[105][105];
bool vis[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int count(int height) {
    for (int i = 0; i < 105; i++) fill(vis[i], vis[i] + 105, 0);
    queue<pair<int, int>> Q;
    int areaNum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //이미 방문했거나 잠기는 지역은 pass
            if (vis[i][j] || board[i][j] <= height) continue;
            vis[i][j] = 1;
            Q.push({i, j});
            areaNum++;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] <= height) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return areaNum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            h[board[i][j]] = 1;
        }
    for (int i = 1; i < 101; i++) {
        if (h[i]) {
            ans = max(ans, count(i));
        }
    }
    if(ans==0){
        cout<<1;
        return 0;
    }
    cout << ans;
}
