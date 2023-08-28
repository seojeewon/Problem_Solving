//2023-08-25.
#include "bits/stdc++.h"

using namespace std;

bool isEnd(string s){
    bool ans = false;
    for(char c : s){
        if(c=='-') ans=true;
    }
    return ans;
}

int func(string s){
    int ans=0;
    stack<char> st;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='{'){
            st.push(s[i]);
        } else{ //s[i]=='}'
            if(!st.empty())
                st.pop();
            else{
                if(s[i+1]=='{')
                    ans+=2;
                else
                    ans++;
                //s.erase(i+1, i+1);
                i++;
            }
        }
    }
    if(!st.empty()){
        ans+=st.size()/2;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int cnt=1;
    while(true){
        getline(cin, s);
        if(isEnd(s)) break;
        int a = func(s);
        cout<<cnt<<". "<<a<<'\n';
        cnt++;
    }
}
