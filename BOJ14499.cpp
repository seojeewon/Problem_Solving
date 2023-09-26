//2023-09-25.
#include "bits/stdc++.h"

using namespace std;
int n, m, k;
int bottom = 6;   //맨 처음 전개도 상에서 밑에 위치한 것은 6번면
int board[22][22];  //지도
int dx[5] = {0,0, 0, -1, 1};   //동서북남
int dy[5] = {0,1, -1, 0, 0};
int dice[7];
int north[7] = {0, 2, 6, 2, 2, 1, 5};
int south[7] = {0, 5, 1, 5, 5, 6, 2};
int west[7] = {0, 4, 4, 1, 6, 4, 4};
int east[7] = {0, 3, 3, 6, 1, 3, 3};
enum DIRECTION {
    NON, EAST, WEST, NORTH, SOUTH
};

void make_bottom(int dir) {
    switch (dir) {
        case EAST:
            bottom = east[bottom];
            break;
        case WEST:
            bottom = west[bottom];
            break;
        case SOUTH:
            bottom = south[bottom];
            break;
        case NORTH:
            bottom = north[bottom];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x, y;    //주사위 좌표
    cin >> x >> y;
    cin >> k; //명령 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    while (k--) {
        int dir;
        cin >> dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //지도 벗어남
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        x = nx;
        y = ny; //주사위 이동
        make_bottom(dir);   //밑면 이동
        if (board[x][y] != 0) { //이동 칸 수가 0이 아닌 경우
            dice[bottom] = board[x][y];
        } else { //이동 칸의 수가 0인 경우
            board[x][y] = dice[bottom];
        }
        cout << dice[7 - bottom] << '\n';
    }
}
