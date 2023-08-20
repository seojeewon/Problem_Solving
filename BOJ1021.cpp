//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, loc, ans = 0;
    deque<int> dq;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    while (m--) {
        int cnt = 0;    //위치가 현재 몇번째에 있는지
        int size = dq.size();
        cin >> loc;
        //int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치
        for (auto iter = dq.begin(); iter != dq.end(); iter++) {
            if (*iter == loc)
                break;
            cnt++;
        }
        if (cnt <= size - cnt) {  //2번 연산 - 왼쪽 이동
            for (int i = 0; i < cnt; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
                ++ans;
            }
            dq.pop_front(); //1번 연산
        } else {   //오른쪽 이동
            for (int i = 0; i < size - cnt; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
                ++ans;
            }
            dq.pop_front(); //1번 연산
        }
    }
    cout << ans;
}