//2023-09-07.
#include "bits/stdc++.h"
using namespace std;
int n;
string r[4]={
        "\"����Լ��� ������?\"\n",
        "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
        "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
        "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n"
};
string e = "��� �亯�Ͽ���.";
void func(int k){
    if(k==n){
        for(int i=0;i<4*k;i++) cout<<'_';
        cout<<"\"����Լ��� ������?\"\n";
        for(int i=0;i<4*k;i++) cout<<'_';
        cout<<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for(int i=0;i<4*k;i++) cout<<'_';
        cout<<e<<'\n';
        return;
    }
    if(k==0){
        cout<<"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n"<<r[0]<<r[1]<<r[2]<<r[3];
        func(k+1);
        cout<<e;
        return;
    }
    for(int j=0;j<4;j++){
        for(int i=0;i<4*k;i++) cout<<'_';
        cout<<r[j];
    }
    func(k+1);
    for(int i=0;i<4*k;i++) cout<<'_';
    cout<<e<<'\n';

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
}
