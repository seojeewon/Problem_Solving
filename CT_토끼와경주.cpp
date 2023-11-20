#include "bits/stdc++.h"
#define NM 2005
using namespace std;

//토끼
struct Rabbit {
    int pid;  //토끼의 pid와 이동거리
    int x, y;    //토끼의 좌표:x행 y열
    int jump;

    bool operator<(const Rabbit ot) const {
        //비교 조건
        //현재까지의 총 점프 횟수가 적은 토끼
        if (jump != ot.jump) return jump > ot.jump;
        //현재 서있는 행 번호 + 열 번호가 작은 토끼
        if (x + y != ot.x + ot.y) return x + y > ot.x + ot.y;
        //행 번호가 작은 토끼
        if (x!=ot.x) return x>ot.x;
        //열 번호가 작은 토끼
        if(y!=ot.y) return y>ot.y;
        //고유번호가 작은 토끼
        return pid>ot.pid;

    }
};

int N, M, P;
unordered_map<int,int> dist;   //i번 토끼의 이동거리
unordered_map<int,long long int> score; //i번 토끼의 점수
priority_queue<Rabbit> rabbits;
long long int total_shift;
void init() {   //초기화 함수
    cin>>N>>M>>P;
    for(int i=0;i<P;i++){
        int pid, d;
        cin>>pid>>d;
        rabbits.push({pid, 1, 1, 0});
        dist[pid]=d;
    }
}
void move_right(int *y, int *d){    //x,y에서 d만큼 오른쪽 이동을 시도. 만약 오른쪽 끝에 도달하면 멈추는 함수
    if(M-*y>=*d){   //오른쪽 끝까지의 거리보다 작거나 같게 이동하면, 바로 이동
        *y+=*d;
        *d=0;
    } else{
        *d -= M - *y;
        *y=M;
    }
}
void move_left(int *y, int *d){    //x,y에서 d만큼 오른쪽 이동을 시도. 만약 오른쪽 끝에 도달하면 멈추는 함수
    if(*y-1>=*d){   //오른쪽 끝까지의 거리보다 작거나 같게 이동하면, 바로 이동
        *y-=*d;
        *d=0;
    } else{
        *d -= *y-1;
        *y=1;
    }
}
void move_up(int *x, int *d){    //x,y에서 d만큼 오른쪽 이동을 시도. 만약 오른쪽 끝에 도달하면 멈추는 함수
    if(*x-1>=*d){   //오른쪽 끝까지의 거리보다 작거나 같게 이동하면, 바로 이동
        *x-=*d;
        *d=0;
    } else{
        *d -= *x-1;
        *x=1;
    }
}
void move_down(int *x, int *d){    //x,y에서 d만큼 오른쪽 이동을 시도. 만약 오른쪽 끝에 도달하면 멈추는 함수
    if(N-*x>=*d){   //오른쪽 끝까지의 거리보다 작거나 같게 이동하면, 바로 이동
        *x+=*d;
        *d=0;
    } else{
        *d -= N - *x;
        *x=N;
    }
}
pair<int,int> getGoal(int cx, int cy, int cd){ //(x,y)에서 d만큼 뛰면 어디로 가야 하는지
    vector<pair<int,int>> goals;
    {
        //오른쪽으로 이동하기
        int period = (M-1)*2;
        int x = cx, y=cy;
        int d =cd%period;

        move_right(&y, &d);
        move_left(&y, &d);
        move_right(&y, &d);
        goals.push_back({x,y});
    }
    {
        //왼쪽으로 이동하기
        int period = (M-1)*2;
        int x = cx, y=cy;
        int d =cd%period;

        move_left(&y, &d);
        move_right(&y, &d);
        move_left(&y, &d);
        goals.push_back({x,y});
    }
    {
        //위쪽으로 이동하기
        int period = (N-1)*2;
        int x = cx, y=cy;
        int d =cd%period;

        move_up(&x, &d);
        move_down(&x, &d);
        move_up(&x, &d);
        goals.push_back({x,y});
    }
    {
        //아래쪽으로 이동하기
        int period = (N-1)*2;
        int x = cx, y=cy;
        int d =cd%period;

        move_down(&x, &d);
        move_up(&x, &d);
        move_down(&x, &d);
        goals.push_back({x,y});
    }
    sort(goals.begin(),goals.end(),[](pair<int,int> A, pair<int,int> B){
        if(A.first+A.second!=B.first+B.second) return A.first+A.second>B.first+B.second;
        if(A.first!=B.first) return A.first>B.first;
        return A.second>B.second;
    });
    return goals[0];
}
void getWinner(unordered_map<int,Rabbit> candidates, int S){
    //candidates: 점수 받을 가능성이 있는 토끼들
    Rabbit r = (*candidates.begin()).second;
    for(auto it = candidates.begin();it!=candidates.end();it++){
        Rabbit ot = (*it).second;
        if(r.x+r.y != ot.x + ot.y){
            if(r.x+r.y<ot.x+ot.y){
                r=ot;
            }
            continue;
        }
        if(r.x!=ot.x){
            if(r.x<ot.x){
                r=ot;
            }
            continue;
        }
        if(r.pid!=ot.pid){
            r=ot;
        }
    }
    score[r.pid]+=S;
}
void rabbit_jump() {    //k번의 점프 수행
    int K, S;
    cin>>K>>S;
    unordered_map<int, Rabbit> candidates;   //한 번이라도 뽑힌 적 있는 토끼
    while(K--){
        //1. 이번에 점프할 토끼 선정
        Rabbit r = rabbits.top();
        rabbits.pop();
        //2. 해당 토끼 이동 위치 선정
        pair<int,int> goal=getGoal(r.x,r.y,dist[r.pid]);
        //3. 토끼 이동
        r.x=goal.first;
        r.y=goal.second;
        r.jump+=1;
        candidates[r.pid]=r;
        rabbits.push(r);
        //4. 점수 갱신
        score[r.pid]-=r.x+r.y;  //이 토끼의 점수가 안 오르게 변경
        total_shift+=r.x+r.y;   //모든 토끼가 r.x+r.y만큼 오른다고 갱신
    }
    //S 점수만큼 점수 받을 토끼 선정
    getWinner(candidates,S);
}

void rabbit_update() {  //특정 토끼의 이동 거리 update
    int pid,L;
    cin>>pid>>L;
    dist[pid]*=L;
}

void best_rabbit() {    //최고의 점수를 갖는 토끼 출력
    long long int ans=0;
    for(auto iter = score.begin();iter!=score.end();iter++){
        ans=max(ans,iter->second);
    }
    cout<<ans+total_shift;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q;
    cin >> Q;
    while (Q--) {
        int query_type;
        cin >> query_type;
        if (query_type == 100) {
            init();
        } else if (query_type == 200) {
            rabbit_jump();
        } else if (query_type == 300) {
            rabbit_update();
        } else {
            best_rabbit();
        }
    }
}