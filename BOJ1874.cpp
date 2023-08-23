//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin>>n;

    queue<int> q;
    for(int i=1 ; i<=n ; i++)
        q.push(i);
    vector<char> v; //연산 저장
    stack<int> st;
    while(n--){
        cin>>num;
        if(st.empty() || st.top()<num){
            st.push(q.front()); q.pop(); v.push_back('+');
            while(st.top()!=num){
                st.push(q.front());
                q.pop();
                v.push_back('+');
            }
            st.pop();
            v.push_back('-');
        } else if(st.top()==num){
            st.pop();
            v.push_back('-');
        } else{
            cout<<"NO";
            return 0;
        }
    }
    for(char c : v)
        cout<<c<<'\n';
}
