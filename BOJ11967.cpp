//2023-08-24.
#include "bits/stdc++.h"

using namespace std;
map<pair<int, int>, vector<pair<int, int>>> M;
int board[101][101];    //불
bool vis[101][101]; //방문 여부
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans=0;
    queue<pair<int, int>> Q;
    cin>>n>>m;

    while(m--){
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        if(M.find({x,y})==M.end()){
            vector<pair<int, int>> v={{a,b}};
            M[{x,y}]=v;
        } else{
            M[{x,y}].push_back({a,b});
        }
    }
    board[1][1]=1;
    vis[1][1]=true;
    Q.push({1,1});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(M.find({cur.first,cur.second})!=M.end()){
            for(auto p : M[{cur.first, cur.second}])    //스위치 켜기
                board[p.first][p.second]=1;
        }
        for()
    }
}
