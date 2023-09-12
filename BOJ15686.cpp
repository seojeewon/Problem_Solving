//2023-09-10.
#include "bits/stdc++.h"

using namespace std;
int n, m, minCost = 100;
int board[55][55];

int calc(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int func2(vector<pair<int, int>> &live) {
    int chickenPath = 100;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 1) continue;
            for (int k = 0; k < m; k++)
                chickenPath = min(chickenPath, calc({i, j}, live[k]));
            ans += chickenPath;
            chickenPath = 100;
        }
    return ans;
}

void func1(vector<pair<int, int>> &c) {
    vector<pair<int, int>> live(m);
    do {
        for (int i = 0; i < m; i++)
            live[i] = c[i];
        minCost = min(func2(live), minCost);
        reverse(c.begin() + m, c.end());
    } while (next_permutation(c.begin(), c.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> chicken;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken.push_back({i, j});
                board[i][j] = 0;
            }
        }
    func1(chicken);
    cout << minCost;
}