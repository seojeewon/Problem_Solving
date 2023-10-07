//2023-09-30.
#include "bits/stdc++.h"
using namespace std;
int n,m;
int board[8][8];

int dx[3]={1,1,1};
int dy[3]={-1,0,1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    int ans=1000;
    for(int r=0;r<m;r++){
        int cost[8][8];
        cost[0][r]=board[0][r];
        pair<int,int> start = {0,r};
        queue<pair<int,int>> Q;
        Q.push(start);
        while(!Q.empty()){
            auto cur=Q.front();Q.pop();
            for(int dir=0;dir<3;dir++){
                int nx=cur.first+dx[dir];
                int ny=cur.second+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                cost[nx][ny]=cost[cur.first][cur.second];
                Q.push({nx,ny});
            }
        }
        int mi=cost[n-1][0];
        for(int i=1;i<m;i++)
            mi=min(mi,cost[n-1][i]);
        ans=min(mi,ans);
    }
    cout<<ans;
    return 0;
}
