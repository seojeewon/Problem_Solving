//2023-09-09.
#include "bits/stdc++.h"

using namespace std;
int a, b;
map<int, long long> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    cin >> a >> b;
    m[a] = 1;
    Q.push(a);
    while (!Q.empty()) {
        if (m[b]) {
            cout << m[b];
            return 0;
        }
        int cur = Q.front();
        Q.pop();
        for (long long nx: {cur << 1, cur * 10 + 1}) {
            if (nx > b || m[nx]) continue;
            m[nx] = m[cur] + 1;
            Q.push(nx);
        }
    }
    cout << -1;
}