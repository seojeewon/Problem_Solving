//2023-10-07.
#include "bits/stdc++.h"
using namespace std;
int n;
bool cmp(int a, int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    sort(b.begin(),b.end());
    sort(a.begin(),a.end(),cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=a[i]*b[i];
    cout<< ans;
}