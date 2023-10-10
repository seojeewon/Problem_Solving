#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int n, m, k;    //포탑의 행, 열, 턴 반복횟수
int board[12][12];  //포탑 지도 정보
bool isAttack[12][12];  //해당 턴 공격 관련 여부
int lastAttack[12][12]; //마지막 공격한 턴이 언제인가?

bool is_finished() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0) cnt++;
        }
    return cnt == 1;  //여기서 if로 분기하지 않고 바로 넣는 스킬
}

//x, y에 있는 포탑이 power 만큼의 공격 받는다.
int attack(int x, int y, int power) {
    isAttack[x][y] = true;
    return max(0, board[x][y] - power);
}

//공격자 선정
pair<int, int> select_attacker() {
    int minValue=2100000000, maxT=-1, maxR=0, maxC=0;
    for(int sum=n+m-2;sum>=0;sum--){    //행+열을 최대부터 최소까지 순회
        for(int c=m-1;c>=0;c--){    //같은 sum에 대해서는 큰 열부터 탐색
            int r = sum-c;  //행
            //현재 보고 있는 좌표 (r,c)
            if(r<0||r>=n) continue; //행 범위 벗어나면 무시
            if(board[r][c]==0) continue;    //부서진 포탑이면 무시
            if(minValue>board[r][c]){
                minValue=board[r][c];
                maxT=lastAttack[r][c];
                maxR=r; maxC=c;
            }
            else if(minValue==board[r][c]&&maxT<lastAttack[r][c]){
                minValue=board[r][c];
                maxT=lastAttack[r][c];
                maxR=r; maxC=c;
            }
        }
    }
    return {maxR, maxC};
}

//타겟 선정
pair<int, int> select_target() {
    int maxValue=-1, minT=2100000000, minR, minC;
    for(int sum=0;sum<=n+m-2;sum++){
        for(int c=0;c<m;c++){
            int r = sum-c;
            if(r<0||r>=n) continue;
            if(board[r][c]==0) continue;
            if(maxValue<board[r][c]){
                maxValue=board[r][c];
                minT=lastAttack[r][c];
                minR=r; minC=c;
            }
            else if(maxValue==board[r][c]&&minT>lastAttack[r][c]){
                maxValue=board[r][c];
                minT=lastAttack[r][c];
                minR=r; minC=c;
            }
        }
    }
    return {minR, minC};
}

//레이저 공격 시도, 실패시 false return, 최단거리=>BFS
//BFS로 최단 경로 찾고, 그 경로까지 찾아야 할땐?
bool try_raser(pair<int, int> atk, pair<int, int> tgt) {
    bool vis[12][12];   //x행 y열에 대한 방문 여부
    for(int i=0;i<12;i++)
        fill(vis[i], vis[i]+12,false);
    pair<int,int> come[12][12];   //x행 y열이 어디로부터 왔는가?
    //우->하->좌->상 순서로 BFS 순회
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    queue<pair<int,int>> Q;
    vis[atk.X][atk.Y]=1;
    Q.push(atk);
    //경로찾기
    while(!Q.empty()){
        auto cur=Q.front();Q.pop();
        for(int dir=0;dir<4;dir++){
            //격자를 벗어났을 때 돌아오는 테크닉
            //n,m을 더하는 이유는 만약 0,0에서 위로 이동하면 -1%4를 하게 되는데 컴퓨터는 이걸 잘 처리 못함
            int nx=(cur.X+dx[dir]+n)%n;
            int ny=(cur.Y+dy[dir]+m)%m;
            if(vis[nx][ny]) continue;   //이미 방문했다면 무시
            if(board[nx][ny]==0) continue;      //부서진 포탑 무시
            come[nx][ny]=cur;   //어디로부터 왔는지 기록
            vis[nx][ny]=1;
            Q.push({nx,ny});
        }
    }
    //만약 레이저가 도달하지 못했다면 false return
    if(!vis[tgt.X][tgt.Y])
        return false;
    //이제 공격으로 데미지 입히기
    int x=tgt.X, y=tgt.Y;
    while(x!=atk.X||y!=atk.Y){  //여기서 왜 OR을 썼을까
        //power 공격력 정하기
        int power = board[atk.X][atk.Y]/2;
        if(x==tgt.X&&y==tgt.Y){
            power=board[atk.X][atk.Y];
        }
        //공격하기
        board[x][y]= attack(x,y, power);
        //역추적하기
        tie(x,y)=come[x][y];
    }
    return true;
}

void bomb(pair<int, int> atk, pair<int, int> tgt) {
    for(int dx : {-1,0,1})
        for(int dy:{-1,0,1}){
            int nx=(tgt.X+dx+n)%n;
            int ny=(tgt.Y+dy+m)%m;
            //공격자는 공격받지 않음
            if(nx==atk.X&&ny==atk.Y) continue;
            int power=board[atk.X][atk.Y]/2;
            if(nx==tgt.X&&ny==tgt.Y)
                power=board[atk.X][atk.Y];
            board[nx][ny]=attack(nx,ny,power);
        }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    //시뮬레이션 시작
    for (int time = 1; time <= k; time++) {
        if (is_finished()) break; //만약 부서지지 않은 포탑이 1개가 된다면 그 즉시 중지
        //1. 공격자 선정
        pair<int, int> atk = select_attacker();
        //2. 공격 대상 선정
        pair<int, int> tgt = select_target();
        //3. 공격자에게 핸디캡 적용
        board[atk.X][atk.Y] += n + m;
        //4. 공격자에 대해 마지막 공격턴 정보 갱신
        lastAttack[atk.X][atk.Y] = time;
        //5. 공격
        //공격 전 isAttack 초기화
        for (int i = 0; i < n; i++)
            fill(isAttack[i], isAttack[i] + m, false);
        isAttack[atk.X][atk.Y] = true;
        //레이저 공격 안되면, 포탄 공격
        if (!try_raser(atk, tgt)) {
            bomb(atk, tgt);
        }
        //6. 정비
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {   //공격에 가담하지 않은 포탑이면 공격력 1 증가
                if (!isAttack[i][j] && board[i][j] != 0) board[i][j] += 1;
            }
    }

    //pair<int,int> result = select_target();
    int ans=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans=max(ans, board[i][j]);
    cout<<ans;

}