//2023-08-22.
/**
 * 규칙 *
 * 1. n-1개를 1->2로 옮긴다
 * 2. n번째 원판을 1->3
 * 3. n-1개를 2->3으로 옮긴다
 */
#include "bits/stdc++.h"

using namespace std;

void hanoi(int n, int h1, int h2) {
    if (n == 1) {
        cout << h1 << ' ' << h2 << '\n';
        return;
    }
    hanoi(n - 1, h1, 6 - h1 - h2);
    cout << h1 << ' ' << h2 << '\n';
    hanoi(n - 1, 6 - h1 - h2, h2);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';   //횟수
    hanoi(n, 1, 3);

}
