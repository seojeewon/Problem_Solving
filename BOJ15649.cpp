//2023-08-26.
#include "bits/stdc++.h"

using namespace std;

int n,m;    //1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열
int arr[10];    //수열 저장
bool isUsed[10];    //특정 수가 쓰였는지

void func(int k){   //현재까지 k개의 수를 채움->arr[k]를 정하자.
    if(k==m) {    //m개를 모두 채웠으면
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';  //arr에 기록한 수열 출력
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!isUsed[i]){
            arr[k]=i;
            isUsed[i]=true;
            func(k+1);
            isUsed[i]=false;    //k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지 않았다고 명시
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    func(0);
}
