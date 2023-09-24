//2023-09-23.
#include "bits/stdc++.h"

#define X first
#define Y second
using namespace std;
int n, k, l;   //보드 크기, 사과 개수, 방향 변환 횟수
int board[102][102];
int ground[102][102];    //뱀
vector<pair<int, char>> cmd;    //방향 변환 정보
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //입력
    cin >> n >> k;
    int appleX, appleY;
    for (int i = 0; i < k; i++) {
        cin >> appleX >> appleY;
        board[appleX - 1][appleY - 1] = 1;    //1,1시작이기 때문
    }
    cin >> l;
    int cTime = 0;
    char cDir;
    for (int i = 0; i < l; i++) {
        cin >> cTime >> cDir;
        cmd.push_back({cTime, cDir});
    }
    //simulation 시작
    deque<pair<int, int>> snake;
    snake.push_back({0, 0}); //처음에는 길이 1짜리 뱀
    ground[0][0] = 1;
    int dir = 1;  //처음 뱀의 방향:오른쪽
    int idx = 0; //몇번째 cmd
    for (int time = 1; time < 1000000; time++) {
        dir %= 4;
        int nx = snake[0].X + dx[dir];
        int ny = snake[0].Y + dy[dir];
        //가고자 하는 방향이 벽일 때
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            cout << time;
            return 0;
        }
        //가고자 하는 방향에 자기자신의 몸이 있을 때
        if (ground[nx][ny] == 1) {
            cout << time;
            return 0;
        }
        //가고자 하는 방향에 사과가 있을 때
        if (board[nx][ny] == 1) {
            board[nx][ny] = 0;    //사과 없어짐
            snake.push_front({nx, ny});
            ground[nx][ny] = 1;    //머리 이동, 꼬리 그대로
        }
            //사과 없음
        else {
            ground[snake[snake.size() - 1].X][snake[snake.size() - 1].Y] = 0;
            snake.pop_back();
            ground[nx][ny] = 1;
            snake.push_front({nx, ny});
        }
        //cmd 확인
        if (idx < l && time == cmd[idx].first) {
            if (cmd[idx].second == 'L') {
                dir += 3;
            } else {
                dir++;
            }
            idx++;
        }
    }
}
