//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

bool cmp(tuple<int, string, int> &p1, tuple<int, string, int> &p2) {
    if (get<0>(p1) == get<0>(p2))
        return get<2>(p1) < get<2>(p2);
    return get<0>(p1) < get<0>(p2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<int, string, int>> v;
    for (int i = 0; i < n; i++) {
        int a; string b;
        cin >> a>>b;
        v.push_back(make_tuple(a, b, i));
    }
    sort(v.begin(), v.end(), cmp);
    for (auto c: v)
        cout << get<0>(c) << ' ' << get<1>(c) << '\n';
}