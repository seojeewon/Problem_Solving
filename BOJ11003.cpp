//2023-09-07.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin>>n>>l;
    vector<int> v(n,0);
    deque<int> deq;
    for(int i=0;i<n;i++) cin>>v[i];
    int min=v[0];
    deq.push_back(v[0]);
    cout<<min<<' ';
    for(int i=1;i<l;i++){
        deq.push_back(v[i]);
        if(v[i]<min) min=v[i];
        cout<<min<<' ';
    }
    for(int i=l;i<n;i++){
        if(deq.front()==min){
            deq.pop_front();
            deq.push_back(v[i]);
            ;
        } else{
            deq.pop_front();
            deq.push_back(v[i]);
            if(v[i]<min) min=v[i];
        }
    }
}