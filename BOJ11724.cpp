//2023-11-30.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;   //정점, 간선
vector<int> adj[1002];
bool vis[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int num = 0;    //연결 요소의 개수
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        num++;
        Q.push(i);
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            int idx = 0;
            while (idx < adj[cur].size()) {
                if (vis[adj[cur][idx]]) {
                    idx++;
                    continue;
                }
                vis[adj[cur][idx]] = 1;
                Q.push(adj[cur][idx]);
                idx++;
            }
        }
    }

    cout << num;

}
