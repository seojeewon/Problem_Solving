//2023-10-07.
#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    long long ans= v[0]*n;
    for(int i=1;i<n;i++){
        if(v[i]*(n-i)>ans) ans=v[i]*(n-i);
    }
    cout<<ans;
}