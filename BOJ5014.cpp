//2023-09-09.
#include "bits/stdc++.h"

using namespace std;
int f, s, g, u, d;
int flr[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(flr, flr + 1000003, -1);
    queue<int> Q;
    cin >> f >> s >> g >> u >> d;
    flr[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        if(flr[g]!=-1) break;
        int cur = Q.front();
        Q.pop();
        for (int nx: {cur - d, cur + u}) {
            if (nx < 1 || nx > f) continue;
            if (flr[nx]>-1) continue;
            flr[nx] = flr[cur] + 1;
            Q.push(nx);
        }
    }
    if (flr[g] != -1) cout << flr[g];
    else cout << "use the stairs";
}
