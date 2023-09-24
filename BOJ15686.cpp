//2023-09-23.
#include "bits/stdc++.h"

using namespace std;
int n, m;    //도시 크기, 장사 지속할 치킨집 개수
int board[51][51];  //도시
vector<pair<int, int>> chicken;
vector<pair<int, int>> chosen(15);
bool vis[15];
int idx;
int ans = 2100000000;

int brute(int x, int y) {
    int mini = 2100000000;
    for (int i = 0; i < m; i++) {
        int temp = abs(x - chosen[i].first) + abs(y - chosen[i].second);
        mini = min(mini, temp);
    }
    return mini;
}

void choice(int k) {
    if (k == m) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) sum += brute(i, j);
            }
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < chicken.size(); i++) {
        if (vis[i] || idx > i) continue;
        chosen[k] = chicken[i];
        vis[i] = 1;
        idx = i;
        choice(k + 1);
        vis[i] = 0;
        idx = i - 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    //입력받기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    choice(0);
    cout << ans;
}