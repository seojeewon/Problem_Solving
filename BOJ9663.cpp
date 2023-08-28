//2023-08-26.
/**
 * 여러 번 복습하기
 * isUsed를 두어 각 열과 대각선의 점유상태를 기록할 수 있다.
 */
#include "bits/stdc++.h"

using namespace std;

int n, cnt;
bool isUsed1[15];   //열 점유상태
bool isUsed2[29];   // /대각선
bool isUsed3[29];   // \대각선

void func(int k) {  //한 행에 퀸 하나만 놓을 수 있음. k번째 행에 퀸을 놓을 차례
    if (k == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {   //열
        //이미 점유된 라인에 있는 열은 제외
        if (isUsed1[i] || isUsed2[k + i] || isUsed3[k - i + n - 1]) continue;
        //k번째 퀸이 점유하게 되는 영역 표시
        isUsed1[i] = 1;
        isUsed2[k + i] = 1;
        isUsed3[k - i + n - 1] = 1;
        func(k + 1);
        //k번째 퀸이 i, j일때 모든 경우의 수를 다 확인했기 때문에 이전 상태로 되돌린다.
        isUsed1[i] = 0;
        isUsed2[k + i] = 0;
        isUsed3[k - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;

}