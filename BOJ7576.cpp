//2023-08-21.
/**
 * 토마토 문제 - 시작점이 여러 개인 BFS
 * 모든 시작점을 큐에 넣고 BFS를 돌린다.
 */

#include "bits/stdc++.h"

#define X first
#define Y second

using namespace std;

int board[1002][1002]; //토마토 상자
int days[1002][1002];   //익는데 걸리는 날짜
//bool vis[1002][1002];   //방문 여부
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //익는데 필요한 날짜판 초기화
    for (int i = 0; i < 1002; i++)
        fill(days[i], days[i] + 1002, -1);

    int n, m, maxDays = -100;
    queue<pair<int, int>> Q;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];   //1: 익토, 0: 안익토, -1:없음
            if (board[i][j] == 1)  //익은 토마토는 0일 소요
                days[i][j] = 0;
        }


    //seed 찾기
    //처음부터 익은 토마토들을 seed로 해서 한번에 다같이 BFS 돌리고 싶음->싹다 큐에 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (days[nx][ny] == -1 && board[nx][ny] == 0) {
                days[nx][ny] = days[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
                maxDays = max(days[nx][ny], maxDays);
            }
        }
    }
    //안익은 토마토 있는지 검사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && days[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }
    //이미 다 익은 토마토만 있는 경우
    if (maxDays == -100)
        maxDays = 0;
    cout << maxDays;
}