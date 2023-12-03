#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int m;  //계수기 자릿수
int n;  //버튼 누르는 횟수
int func(vector<int> maximum, vector<int> &v, int idx, int r){
    if(r==0) return 0;
    //1증가해도 maximum 안넘어감
    if(v[idx]+r<=maximum[idx]){
        v[idx]+=1;
        return 0;
    }
    //maximum 넘어감
    v[idx]=0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력
    cin>>m;
    vector<int> maximum(m); //계수기 각 자리수의 최대값 저장
    vector<int> v(m);   //계수기

    for(int i=0;i<m;i++)
        cin>>maximum[i];
    for(int i=0;i<m;i++){
        cin>>v[i];
        if(v[i]>maximum[i]){    //종료 조건: 초깃값이 더 큼
            cout<<-1;
            return 0;
        }
    }
    cin>>n;

    for(int i=0;i<n;i++){   //n번 누름
        int r = 1;
        for(int j=m-1;j>=0;j--){
            r=func(maximum, v, j, r);
        }
    }

    for(int i=0;i<m;i++)
        cout<<v[i];

}
