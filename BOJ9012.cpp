//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

string func(string &s){
    string ans="YES\n";
    stack<char> st;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(st.empty())
                return ans="NO\n";
            st.pop();
        }
    }
    if(!st.empty()) ans="NO\n";
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        cout<<func(s);
    }
}

