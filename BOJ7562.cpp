//2023-09-04.
#include "bits/stdc++.h"

using namespace std;
int t, l;
pair<int, int> cur, des;
int dist[301][301];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> l;
        for (int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);
        cin >> cur.first >> cur.second;
        cin >> des.first >> des.second;
        queue<pair<int, int>> Q;
        dist[cur.first][cur.second] = 0;
        Q.push(cur);
        while (dist[des.first][des.second] == -1) {
            auto now = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = now.first + dx[dir];
                int ny = now.second + dy[dir];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[now.first][now.second] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[des.first][des.second] << '\n';
    }
}
