//2023-11-30.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> adj[1003];
bool visB[1003];
bool visD[1002];

void bfs(){
    queue<int> Q;
    visB[s]=1;
    Q.push(s);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout<<cur<<' ';
        for(auto next : adj[cur]){
            if(visB[next]) continue;
            visB[next]=1;
            Q.push(next);
        }
    }
}

void dfs(int cur){
    visD[cur]=1;
    cout<<cur<<' ';
    for(auto next : adj[cur]){
        if(visD[next]) continue;
        dfs(next);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>s;
    int u, v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i=1;i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }


    dfs(s);
    cout<<'\n';
    bfs();
}
