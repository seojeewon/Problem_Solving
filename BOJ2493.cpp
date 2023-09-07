//2023-09-06.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pair<int, int>> v(n, {0, 0});
    vector<int> ans(n, 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        v[i].first = i + 1;
        cin >> v[i].second;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s.empty() || s.top().second > v[i].second){
            s.push(v[i]);
            continue;
        }
        while (!s.empty()) {
            if(s.top().second > v[i].second) break;
            ans[s.top().first] = v[i].first;
            s.pop();
        }
        s.push(v[i]);
    }
    while (!s.empty()) {
        ans[s.top().first] = 0;
        s.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ans[v[i].first] << ' ';
    }
}
