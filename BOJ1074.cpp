//2023-08-22.
/**
 * 재귀 규칙은 빨리 발견했는데, 이상하게 구현에 오래걸림
 * 1. 현재 배열을 사분면으로 나눠서 생각->r,c가 어디 사분면에 위치하는지 확인
 * 2. 각 분면까지 도달하려면 방문해야 하는 칸 수를 계산-2^(2n-2)*k사분면
 * 3. 이제 r,c가 있는 사분면만 보면 됨. 이 사분면의 크기는 2^n-1
 * 따라서 위치를 새로 조정하면 됨.
 */
#include "bits/stdc++.h"

using namespace std;

int func(int n, int r, int c) {
    if (n == 1) {
        if (r == 0 && c == 0) return 0;
        if (r == 0 && c == 1) return 1;
        if (r == 1 && c == 0) return 2;
        return 3;
    }
    int num = 1 << n;
    int pre = 1 << 2 * (n - 1);
    if (r < num / 2 && c < num / 2) {
        return func(n - 1, r, c);
    } else if (r < num / 2 && c >= num / 2) {
        return pre + func(n - 1, r, c - num / 2);
    } else if (r >= num / 2 && c < num / 2) {
        return pre * 2 + func(n - 1, r - num / 2, c);
    } else {
        return pre * 3 + func(n - 1, r - num / 2, c - num / 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}

