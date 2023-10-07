//2023-10-06.
#include "bits/stdc++.h"

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int size=sequence.size();
    vector<int> ans(2,2000000);
    int en=0;
    int min=10000000;
    int sum=sequence[0];
    for(int st=0;st<size;st++){
        if(en<st) en=st;
        while(en<size&&sum<k){
            en++;
            sum+=sequence[en];
        }
        if(sum==k){
            if(en-st+1<min){
                ans[0]=st;
                ans[1]=en;
                min=en-st+1;
            }
        }
        sum-=sequence[st];
    }
    return ans;
}
