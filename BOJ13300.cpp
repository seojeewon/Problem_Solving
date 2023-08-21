//2023-08-21.

#include "bits/stdc++.h"

using namespace std;

int girl[6];
int boy[6];
//2차원 배열로 설정할 수도 있음.

int countRoom(int num, int k) {
    if (num % k) {
        return num / k + 1;
    }
    return num / k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;

    //각 학년, 성별당 몇명인지 카운트
    while (n--) {
        int g, y;  //성별, 학년
        cin >> g >> y;
        if (g == 0) {   //여자
            girl[y - 1]++;
        } else {   //남자
            boy[y - 1]++;
        }
    }

    for (int i = 0; i < 6; i++) {
        ans += countRoom(girl[i], k) + countRoom(boy[i], k);
    }
    cout << ans;
}
