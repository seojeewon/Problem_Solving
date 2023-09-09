//2023-09-08.
#include "bits/stdc++.h"
using namespace std;
char s[7000][7000];
void func(int k, int x, int y){
    if(k==3){
        s[x+1][y+1]=' ';
        return;
    }
    for(int i=x+k/3;i<x+2*k/3;i++){
        for(int j=y+k/3;j<y+2*k/3;j++)
            s[i][j]=' ';
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            func(k/3, x+(k/3)*i, y+(k/3)*j);
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<7000;i++) fill(s[i], s[i]+7000, '*');
    func(n, 0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<s[i][j];
        cout<<'\n';
    }
}
