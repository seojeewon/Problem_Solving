#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
int n, w;   //행렬 크기, 회전수
string board[102][102];
string ans[102][102];


void func(int level, int dir){
    //queue에 넣기
    deque<string> Q;
    //윗변
    for(int j=level;j<n-level;j++)
        Q.push_back(board[level][j]);
    //우변
    for(int i=level+1;i<n-level-1;i++)
        Q.push_back(board[i][n-level-1]);
    //밑변
    for(int j=n-level-1;j>=level;j--)
        Q.push_back(board[n-level-1][j]);
    //좌변
    for(int i=n-level-2;i>=level+1;i--)
        Q.push_back(board[i][level]);

    //회전
    if(dir>0){
        for(int i=0;i<dir;i++){
            Q.push_front(Q.back());
            Q.pop_back();
        }
    }
    else{
        int tmp = -dir;
        for(int i=0;i<tmp;i++){
            Q.push_back(Q.front());
            Q.pop_front();
        }
    }
    //ans에 붙이기
    //윗변
    for(int j=level;j<n-level;j++){
        ans[level][j]=Q.front(); Q.pop_front();
    }
    //우변
    for(int i=level+1;i<n-level-1;i++){
        ans[i][n-level-1]=Q.front(); Q.pop_front();
    }
    //밑변
    for(int j=n-level-1;j>=level;j--){
        ans[n-level-1][j]=Q.front(); Q.pop_front();
    }
    //좌변
    for(int i=n-level-2;i>=level+1;i--){
        ans[i][level]=Q.front(); Q.pop_front();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>w;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    if(n==1){
        cout<<board[0][0];
        return 0;
    }

    for(int i=0;i<n/2;i++){
        func(i, w);
        w=-w;
    }
    //n이 홀수인 경우
    if(n%2){
        ans[n/2][n/2]=board[n/2][n/2];
    }

    //출력
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}