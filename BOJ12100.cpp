//2023-09-21.
#include "bits/stdc++.h"

using namespace std;
int n;  //보드 크기<=20
int board[22][22];
int board2[22][22];
int temp[22][22];
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            board2[i][j]=board[i][j];
    }
}
void tiltld(){  //O(n^2)
    int arr[8]={0,2,0,2,8,8,0,16};
    int tilted[8]={};   //결과 저장
    bool merged[8]={};  //이미 합쳐진 숫자인지 여부
    for(int i=0;i<8;i++){
        if(arr[i]==0) continue;
        if(tilted[0]==0){
            tilted[0]=arr[i];
            continue;
        }
        int idx=i;
        while(tilted[idx]==0) idx--;
        if(!merged[idx]&&tilted[idx]==arr[i]){
            merged[idx]=1;
            tilted[idx]*=2;
        }
        else{
            tilted[idx+1]=arr[i];
        }
    }
}
void tiltld2(){
    int arr[8]={0,2,0,2,8,8,0,16};
    int tilted[8]={};
    int idx=0;  //다음 arr에서의 블록이 들어갈 수 있는 위치
    for(int i=0;i<8;i++){
        if(arr[i]==0) continue;
        if(tilted[idx]==0){
            tilted[idx]=arr[i];
        }
        else if(tilted[idx]==arr[i])
            tilted[idx++]*=2;
        else
            tilted[++idx]=arr[i];
    }
}
//시계방향 회전
void rotate(){
    int tmp[21][21]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            tmp[i][j]=board2[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            board2[i][j]=tmp[n-1-j][i];
    }
}
void tilt(int dir){
    //회전시킨 후 왼쪽으로 기울인다.
    //기울인 후 원래 방향으로 돌려야 하지 않나? No, 최대값만 구하면 됨
    while(dir--) rotate();
    for(int i=0;i<n;i++){   //각 행마다 수행
        int tilted[21]={};
        int idx=0;
        for(int j=0;j<n;j++){   //i번째 행의 각 열
            if(board2[i][j]==0) continue;
            if(tilted[idx]==0){
                tilted[idx]=board2[i][j];
            } else if(tilted[idx]==board2[i][j]){
                tilted[idx++]*=2;
            } else{
                tilted[++idx]=board2[i][j];
            }
        }
        for(int j=0;j<n;j++) board2[i][j]=tilted[j];
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //입력
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];
    //움직이는 방향
    int ans = 0;
    for (int tmp = 0; tmp < (1 << 10); tmp++) {
        init(); //sim 초기화
        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans=max(ans, board2[i][j]);
    }
    cout<<ans;
}