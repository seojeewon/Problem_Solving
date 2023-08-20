//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    string s;
    queue<int> q;

    while(n--){
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(s=="pop"){
            if(q.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(s=="size"){
            cout<<q.size()<<'\n';
        }
        else if(s=="empty"){
            if(q.empty()){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else if(s=="front"){
            if(q.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<q.front()<<'\n';
            }
        }
        else{
            if(q.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<q.back()<<'\n';
            }
        }
    }
}