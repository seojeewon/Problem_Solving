//2023-09-15.
#include "bits/stdc++.h"

using namespace std;
int n, m, ans;

deque<int> calc(vector<int> &ppl, int person) {
    deque<int> tree;
    while (ppl[person] != 0) {
        tree.push_front(person);
        person = ppl[person];
    }
    tree.push_front(person);
    return tree;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> ppl(n, 0);
    int p1, p2;
    cin >> p1 >> p2;
    cin >> m;
    int parent, child;
    for (int i = 0; i < m; i++) {
        cin >> parent >> child;
        ppl[child] = parent;
    }
    deque<int> p1Tree = calc(ppl, p1);
    deque<int> p2Tree = calc(ppl, p2);
    if (p1Tree.front() != p2Tree.front()) {
        cout << -1;
        return 0;
    }
    int i=0;
    while(i<p1Tree.size()&&i<p2Tree.size()&&p1Tree[i]==p2Tree[i]){
        i++;
    }
    if(p1Tree.size()==i){
        while(i<p2Tree.size()){
            ans++;
            i++;
        }
        cout<<ans;
        return 0;
    }
    if(p2Tree.size()==i){
        while(i<p1Tree.size()){
            ans++;
            i++;
        }
        cout<<ans;
        return 0;
    }
    while(i<p1Tree.size()&&i<p2Tree.size()){
        ans+=2;
        i++;
    }
    if(p1Tree.size()==i){
        while(i<p2Tree.size()){
            ans++;
            i++;
        }
        cout<<ans;
        return 0;
    }
    if(p2Tree.size()==i){
        while(i<p1Tree.size()){
            ans++;
            i++;
        }
        cout<<ans;
        return 0;
    }
}