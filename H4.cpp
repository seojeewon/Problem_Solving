#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
string board[12];
bool vis[12][12];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>board[i];
    }

    int num=0;  //영역의 개수
    vector<int> a;  //각 영역의 크기
    queue<pair<int,int>> Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]||board[i][j]=='0') continue;
            vis[i][j]=1;
            Q.push({i,j});
            num++;
            int local=0;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                local++;
                for(int dir=0;dir<4;dir++){
                    int nx = cur.first+dx[dir];
                    int ny=cur.second+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(vis[nx][ny]||board[nx][ny]=='0') continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                }

            }
            a.push_back(local);
        }
    }
    if(num==0){
        cout<<num;
    }
    else{
        cout<<num<<'\n';
        sort(a.begin(), a.end());
        for(int i=0;i<num;i++)
            cout<<a[i]<<' ';
    }


    return 0;
}