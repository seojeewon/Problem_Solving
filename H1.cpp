#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;
int n;  // 배의 크기
int num;    //이동해야 하는 모든 것
unordered_map<string, int> role;

int able;   //배를 몰 수 있는 것의 수
int b;  //강둑에 남겨지면 안 되는 조합의 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin>>num;
    for(int i=0;i<num;i++){
        string s;
        cin>>s;
        role[s]=0;
    }

    cin>>able;
    for(int i=0;i<able;i++){
        string s;
        cin>>s;
        role[s]=1;  //1은 배를 몰 수 있는 사람
    }
    cin>>b;
    //같이 있으면 안되는 애들을 어케 표현하지?????
    for(int i=0;i<b;i++){

    }
}