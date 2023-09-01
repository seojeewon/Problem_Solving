//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
string board[26];
bool vis[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || board[i][j] == '0') continue;
            vis[i][j] = 1;
            Q.push({i, j});
            cnt++;
            int area=0;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                    if (vis[nx][ny] || board[nx][ny] == '0')continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            a.push_back(area);
        }
    if (cnt == 0) {
        cout << cnt;
        return 0;
    }
    cout << cnt << '\n';
    sort(a.begin(), a.end());
    for (int i = 0; i < cnt; i++) cout << a[i] << '\n';
}