//2023-08-26.
#include "bits/stdc++.h"

using namespace std;
int n, s, cnt;
int v[21];

void func(int cur, int tot) {
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + v[cur]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    func(0, 0);
    if(s==0){   //s==0인 경우 공집합 제외
        cout<<cnt-1;
    } else{
        cout << cnt;
    }

}