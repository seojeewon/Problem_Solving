//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    string s;
    stack<int> st;

    while(n--){
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            st.push(x);
        }
        else if(s=="pop"){
            if(st.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<st.top()<<'\n';
                st.pop();
            }
        }
        else if(s=="size"){
            cout<<st.size()<<'\n';
        }
        else if(s=="empty"){
            if(st.empty()){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else{
            if(st.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<st.top()<<'\n';
            }
        }
    }
}