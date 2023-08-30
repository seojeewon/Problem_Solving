//2023-08-29.
#include "bits/stdc++.h"

using namespace std;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> c(n + m, 0);

    int j = 0, k = 0;    //a, b의 index
    for (int i = 0; i < n + m; i++) {
        if (j >= n) c[i] = b[k++];
        else if (k >= m) c[i] = a[j++];
        else {
            if (a[j] <= b[k]) c[i] = a[j++];
            else c[i] = b[k++];
        }
    }
    
    for (int t: c) cout << t << ' ';
}
