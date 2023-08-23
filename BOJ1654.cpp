//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, sum=0, pre_max, newSum=0, max;
    cin>>k>>n;
    vector<int> v(k, 0);
    vector<int> m(k, 0);
    for(int i=0 ; i<k ; i++){
        cin>>v[i];
        sum+=v[i];
    }
    max=sum/n;
    pre_max=max;
    sort(v.begin(), v.end());

    while(true){
        newSum=0;
        for(int i=0 ; i<k ; i++){
            m[i]=v[i]/max;
            newSum+=m[i];
        }
        if(newSum>=n) break;
        pre_max=max;
        max=v[k-1]/(m[k-1]+1);
    }

    cout<<max;
    return 0;
}