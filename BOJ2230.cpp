//2023-10-06.
#include "bits/stdc++.h"

using namespace std;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    //정렬
    sort(a.begin(), a.end());
    //투포인터
    int st = 0, en = 0; //포인터
    int min = 2100000000;
    for (st = 0; st < n; st++) {
        while (en < n && a[en] - a[st] < m) en++;
        if (en >= n) break;
        if (a[en] - a[st] < min) min = a[en] - a[st];
    }
    cout << min;
}
