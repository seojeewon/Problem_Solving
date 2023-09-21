//2023-09-15.
#include "bits/stdc++.h"

using namespace std;
int n, m, ans;
int board[55][55];
bool vis[55][55];
int dx[4] = {1, 0, -1, 0}; //남->서->북->동
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    //처음 시작 좌표
    vis[r][c] = 1;  //방문 표시
    ans++;  //청소한 지역++
    stack<pair<int, int>> s;
    s.push({r, c});
    int dir = (d + 2) % 4;  //처음 위치
    bool flag = false;  //4칸 중 청소되지 않은 빈칸이 있으면 o
    while (true) {
        int i = 0;  //방향키
        auto cur = s.top();
        if(!vis[cur.first][cur.second]){    //2-2의 경우
            vis[cur.first][cur.second]=1;
            ans++;
        }
        while (true) {    //4칸 청소 여부 보기
            flag = false;
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                if(i==3) break;
                //범위 벗어난 경우
                i++;
                dir = (dir + 1) % 4;
                continue;
            }
            if (vis[nx][ny] || board[nx][ny] == 1) {    //이미 청소한 곳이거나 벽
                if(i==3) break;
                i++;
                dir = (dir + 1) % 4;
                continue;
            }
            //청소 안한 빈칸
            s.push({nx, ny});
            flag = true;
            dir=(dir+1)%4;
            break;
        }
        if (flag) continue;
        //네칸중 청소되지 않은 빈 칸이 없음
        if (board[cur.first + dx[(dir + 2) % 4]][cur.second + dy[(dir + 2) % 4]] == 1) {
            cout << ans;
            return 0;
        } else {
            s.push({cur.first + dx[(dir + 2) % 4], cur.second + dy[(dir + 2) % 4]});
        }
    }

}