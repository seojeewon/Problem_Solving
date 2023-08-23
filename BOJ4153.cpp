//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

string func(vector<int> &v){
    sort(v.begin(), v.end());
    if(v[0]*v[0]+v[1]*v[1]==v[2]*v[2]){
        return "right";
    }
    return "wrong";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        vector<int> v(3, 0);
        cin>>v[0]>>v[1]>>v[2];
        if(v[0]==0&&v[1]==0&&v[2]==0) return 0;
        cout<<func(v)<<'\n';
    }
}