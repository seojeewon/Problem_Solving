//2023-09-19.
#include "bits/stdc++.h"

using namespace std;
int n, m;    //사무실의 세로, 가로
int office[10][10]; //사무실
int simul[10][10]; //cctv 방향 시뮬레이션
//방향: 남->서->북->동
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector <pair<int, int>> cctv; //cctv

/**
 * cctv 감시영역 표시
 * x,y에서 dir방향으로 벽을 만날때까지 0을 다 7로 바꿔버림
 */
void upd(int x, int y, int dir) {
    dir = dir % 4;  //dir+3이렇게 들어오는 경우도 있어서
    int nx = x, ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
        if (simul[nx][ny] == 6) break;  //벽
        if (simul[nx][ny] >= 1 && simul[nx][ny] <= 5) continue; //cctv
        simul[nx][ny] = 7;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin >> n >> m;
    int ans = 0;    //사각지대 개수
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctv.push_back({i, j});
            }
            if (office[i][j] == 0) {
                ans++;
            }
        }

    //cctv 방향 정하기
    for (int tmp = 0; tmp < 1 << (2 * cctv.size()); tmp++) {
        //cctv 방향이 정해질 때마다 simul 초기화
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                simul[i][j] = office[i][j];
        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++) { //brute에서 i번째 cctv의 방향을 가져와서 그 cctv 시뮬레이션
            int dir = brute % 4;
            brute /= 4;
            int x, y;   //시뮬레이션 할 cctv의 좌표
            tie(x, y) = cctv[i];
            //cctv 종류에 따라 분류
            if (office[x][y] == 1) {
                upd(x, y, dir);
            } else if (office[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            } else if (office[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            } else if (office[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 3);
            } else {   //5
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
                upd(x, y, dir + 3);
            }
        }
        //사각지대 세기
        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (simul[i][j] == 0) val++;
            }
        }
        ans = min(ans, val);
    }
    cout << ans;
}