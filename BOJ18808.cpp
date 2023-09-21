//2023-09-19.
#include "bits/stdc++.h"

using namespace std;
int n, m, k;  //세로, 가로, 스티커 개수
int note[42][42];   //노트북
int r, c;    //스티커의 행과 열의 개수
int sticker[12][12];    //스티커
void rotate() {
    int tmp[12][12];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = tmp[r - 1 - j][i];
        }
    }
    swap(r, c);
}

bool stickable(int x, int y) {
    //가능 여부 조사
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x + i][y + j] == 1 && sticker[i][j] == 1) return false;
        }
    }
    //가능한 경우-붙이기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j] == 1) note[x + i][y + j] = 1;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        //스티커 입력
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];
        //회전
        //분기점마다 스티커 붙었는지 확인
        for (int rot = 0; rot < 4; rot++) {
            bool isPaste = false;
            for (int x = 0; x <= n - r; x++) {
                if (isPaste) break;
                for (int y = 0; y <= m - c; y++) {
                    if (stickable(x, y)) {
                        isPaste = true;
                        break;
                    }
                }
            }
            if (isPaste) break;
            //여기까지 온거면 못붙인거니까 회전
            rotate();
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (note[i][j] == 1) ans++;
        }
    cout << ans;
}