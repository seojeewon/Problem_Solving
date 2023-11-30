//2023-11-20.
#include "bits/stdc++.h"

using namespace std;
priority_queue<int, vector<int>, greater<>> q1;

int n, l;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>l;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    int minN = 1000000002;
    deque<int> deq;
    vector<int> d(n+1);
    for(int i=1;i<=l;i++){
        q1.push(a[i]);
        d[i]=q1.top();
    }
    for(int i=l+1;i<=n;i++){

    }
}