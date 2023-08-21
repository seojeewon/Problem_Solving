//2023-08-21.

#include "bits/stdc++.h"

#define X first
#define Y second

using namespace std;

int board[501][501];    //그림판
bool vis[501][501];   //방문 표시
int dx[4] = {1, 0, -1, 0};   //상하좌우 방문에 쓰임
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, num = 0, area = 0, maxArea = -1;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && (board[i][j] == 1)) {   //seed 찾기-아직 방문 안하고, 그림이 칠해져 있음
                vis[i][j] = true; //방문 표시
                Q.push({i, j}); //큐에 넣기
                area = 0; //넓이 초기화
                num++;  //그림개수 증가
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();  //큐에서 pop
                    area++;
                    for (int i = 0; i < 4; i++) {   //상하좌우 방문 확인
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;    //도화지 벗어남
                        if (!vis[nx][ny] && board[nx][ny]) {    //방문 안했고 그림 칠해져 있음
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                            //area++;
                        }
                    }
                }
                maxArea = max(maxArea, area);
            }
        }
    }
    if (!num)
        cout << num << '\n' << 0;
    else
        cout << num << '\n' << maxArea;
    return 0;
}