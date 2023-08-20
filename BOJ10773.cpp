//2023-08-20.
//가장 최근에 재민이가 쓴 수를 지운다->스택
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, ans = 0;
    int tmp;
    stack<int> s;
    cin >> k;
    while (k--) {
        cin >> tmp;
        if (tmp == 0)
            s.pop();
        else
            s.push(tmp);
    }
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans;
}