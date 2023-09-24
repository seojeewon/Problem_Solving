//2023-09-23.
#include "bits/stdc++.h"

using namespace std;
vector<deque<int>> wheel(4);
int k;  //회전 횟수
int rot[4]; //각 톱니바퀴의 회전 여부와 방향

void func(){
    for(int i=0;i<4;i++){
        if(rot[i]==0) continue;
        if(rot[i]==1){
            rotate(wheel[i].begin(), wheel[i].begin()+7, wheel[i].end());
        } else{
            rotate(wheel[i].begin(), wheel[i].begin()+1, wheel[i].end());
        }

    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        for (int j = 0; j < 8; j++)
            wheel[i].push_back(tmp[j] - '0');
    }
    cin >> k;
    while (k--) {
        fill(rot, rot + 4, 0);
        int num, dir;
        cin >> num >> dir;
        if (num == 1) {
            rot[0] = dir;
            if (wheel[0][2] != wheel[1][6]) rot[1] = -dir;
            if (wheel[1][2] != wheel[2][6]) rot[2] = -rot[1];
            if (wheel[2][2] != wheel[3][6]) rot[3] = -rot[2];

        } else if (num == 2) {
            rot[1] = dir;
            if (wheel[0][2] != wheel[1][6]) rot[0] = -rot[1];
            if (wheel[1][2] != wheel[2][6]) rot[2] = -rot[1];
            if (wheel[2][2] != wheel[3][6]) rot[3] = -rot[2];

        } else if (num == 3) {
            rot[2] = dir;
            if (wheel[1][2] != wheel[2][6]) rot[1] = -rot[2];
            if (wheel[2][2] != wheel[3][6]) rot[3] = -rot[2];
            if (wheel[0][2] != wheel[1][6]) rot[0] = -rot[1];

        } else {
            rot[3] = dir;
            if (wheel[2][2] != wheel[3][6]) rot[2] = -rot[3];
            if (wheel[1][2] != wheel[2][6]) rot[1] = -rot[2];
            if (wheel[0][2] != wheel[1][6]) rot[0] = -rot[1];

        }

    }
    int ans = 0;
    if (wheel[0][0] == 1) ans += 1;
    if (wheel[1][0] == 1) ans += 2;
    if (wheel[2][0] == 1) ans += 4;
    if (wheel[3][0] == 1) ans += 8;
    cout << ans;
}
