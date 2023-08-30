//2023-08-29.
#include "bits/stdc++.h"

using namespace std;
int n,m;
int b[10];
int arr[10];
bool check[10];

void func(int k){
    if(k==m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(k==0||(arr[k-1]<b[i])){
            arr[k]=b[i];
            check[i]=1;
            func(k+1);
            check[i]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>b[i];
    sort(b,b+n);
    func(0);
}