//2023-08-22.
/**
 * 반례를 잘 찾아야 하는 문제
 * 0. 다양한 루트로 탈출할 수 있음-최소 탈출시간
 * 1. 불이 여러군데 존재할 수 있음-한번에 BFS넣고 돌려야함
 * 2. 불이 없거나, 벽으로 지훈이와 분리되어 있을 수 있음-이 경우 지훈도달시간<불도달시간을 통과 못함.
 * 왜냐하면 불도달시간은 -1이니까.
 */
#include "bits/stdc++.h"

using namespace std;

char board[1002][1002];
int fire[1002][1002];   //불이 도달하는 시간
int man[1002][1002];    //지훈이 도달하는 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //초기화
    for (int i = 0; i < 1002; i++) {
        fill(fire[i], fire[i] + 1002, -1);
        fill(man[i], man[i] + 1002, -1);
    }

    int R, C, time = 0, minTime=1e9;    //행, 열 개수
    bool isEscape = false;  //탈출여부
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            board[i][j] = s[j];
    }

    queue<pair<int, int>> Q;

    //불 먼저 BFS 돌리기 - 지훈이는 하나지만 불은 한번에 여러군데서 날 수 있다
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (board[i][j] != 'F') continue;
            fire[i][j] = 0;   //표시
            Q.push({i, j});
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire[nx][ny] == -1 && board[nx][ny] == '.') {
                fire[nx][ny] = fire[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }



    // 지훈이 BFS 돌리기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] != 'J') continue;
            man[i][j] = 0;   //표시
            Q.push({i, j});
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) {   //가장자리에 도착하면 탈출
                        isEscape = true;
                        time = man[cur.first][cur.second] + 1;
                        minTime=min(time, minTime);
                        continue;
                    }
                    if (man[nx][ny] == -1 && board[nx][ny] == '.') {
                        if(fire[nx][ny]==-1 || man[cur.first][cur.second] + 1<fire[nx][ny]){
                            man[nx][ny] = man[cur.first][cur.second] + 1;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
            if (isEscape)
                cout << minTime;
            else
                cout << "IMPOSSIBLE";
        }
    }
}