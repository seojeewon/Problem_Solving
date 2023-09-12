//2023-09-11.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int a: v)cout << a << '\n';
}