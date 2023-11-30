//2023-11-20.
#include "bits/stdc++.h"

using namespace std;
int n,m;    //방의 크기
int room[55][55];   //방, 0: 청소되지 않은 빈칸, 1: 벽
pair<int,int> cleaner;  //청소기 위치
int dir;    //청소기가 바라보는 방향
int dx[4]={-1,0,1,0};   //북동남서 순서
int dy[4]={0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin>>n>>m;
    cin>>cleaner.first>>cleaner.second;
    cin>>dir;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>room[i][j];
        }
    }

    int ans=0;  //청소하는 영역의 개수
    while(true){
        //1. 현재 칸이 청소되지 않은 경우, 현재 칸 청소
        if(room[cleaner.first][cleaner.second]==0){
            ans++;
            room[cleaner.first][cleaner.second]=2;  //청소를 완료한 칸은 2
        }
        //2. 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는지 확인(반시계)
        bool isExist = false;

        for(int i=3;i<=12;i=i+3){
            int nx = cleaner.first+dx[(dir+i)%4];
            int ny = cleaner.second+dy[(dir+i)%4];
            if(nx>=n||nx<0||ny>=m||ny<0) continue;
            //청소되지 않은 칸이 존재
            if(room[nx][ny]==0){
                isExist=true;
                dir=(dir+i)%4;
                break;
            }

        }
        if(isExist){
            cleaner={cleaner.first+dx[dir], cleaner.second+dy[dir]};
            continue;
        }
        else{
            if(cleaner.first-dx[dir]<0||cleaner.first-dx[dir]>=n||cleaner.second-dy[dir]<0||cleaner.second-dy[dir]>=m){
                break;
            }
            if(room[cleaner.first-dx[dir]][cleaner.second-dy[dir]]==1){
                break;
            }
            //후진
            cleaner={cleaner.first-dx[dir], cleaner.second-dy[dir]};
            continue;
        }
    }

    cout<<ans;
}