//2023-10-07.
#include "bits/stdc++.h"
using namespace std;
int n;
bool cmp(vector<long long> v1, vector<long long> v2){
    if(v1[1]==v2[1])
        return v1[0]<v2[0];
    return v1[1]<v2[1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<vector<long long>> t(n,vector<long long>(2));
    for(int i=0;i<n;i++)
        cin>>t[i][0]>>t[i][1];
    sort(t.begin(),t.end(), cmp);
    int cnt=1;
    long long preEnd=t[0][1];
    for(int i=1;i<n;i++){
        if(t[i][0]<preEnd) continue;
        cnt++;
        preEnd=t[i][1];
    }
    cout<<cnt;
}
