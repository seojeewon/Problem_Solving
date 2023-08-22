//2023-08-22.
#include "bits/stdc++.h"

using namespace std;

int line[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(line, line+100002, -1);

    int n, k;   //수빈, 동생
    queue<int> Q;
    cin>>n>>k;
    if(n==k){   //같은 위치에 있을 경우
        cout<<0;
        return 0;
    }
    line[n]=0;  //수빈이 처음 위치 표시
    Q.push(n);
    while(!Q.empty()){  //line[k]==-1의 조건으로 놓아도 됨.->이렇게 하면 위에 같은 위치에 있는 경우가 저절로 포함됨
        int cur = Q.front(); Q.pop();
        int nx = 0;
        if(cur-1>=0){
            nx = cur-1;
            //for(int nxt: {cur-1, cur+1, cur*2})
            if(line[nx]==-1){   //방문 x
                if(nx==k){
                    cout<<line[cur]+1;
                    return 0;
                }
                line[nx]=line[cur]+1;
                Q.push(nx);
            }

        }
        if(cur+1<=100000){
            nx = cur+1;
            if(line[nx]==-1){   //방문 x
                if(nx==k){
                    cout<<line[cur]+1;
                    return 0;
                }
                line[nx]=line[cur]+1;
                Q.push(nx);
            }
        }
        if(cur*2<=100000){
            nx=cur*2;
            if(line[nx]==-1){   //방문 x
                if(nx==k){
                    cout<<line[cur]+1;
                    return 0;
                }
                line[nx]=line[cur]+1;
                Q.push(nx);
            }
        }
    }

}