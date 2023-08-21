//2023-08-21.

#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int ans = 0;
    cin>>s;

    stack<pair<char, int>> st;
    for(char c : s){
        int tmp = 0;
        if(c=='('||c=='[')
            st.push(pair<char, int>(c, 0));
        else{
            if(st.empty()){ //빈 스택에 닫는 괄호 나오면 오류
                ans=0;
                break;
            }
            if(c==')'){
                while(st.top().first=='&'){
                    tmp+=st.top().second;
                    st.pop();
                }
                if(st.top().first=='('){
                    if(tmp){
                        st.pop();
                        if(!st.empty()){
                            st.push(pair<char, int>('&', tmp*2));
                        } else{
                            ans+=tmp*2;
                        }
                    } else{
                        st.pop();
                        if(!st.empty()){
                            st.push(pair<char, int>('&', 2));
                        } else{
                            ans+=2;
                        }

                    }
                }else{  //)와 짝이 안맞음
                    ans=0;
                    break;
                }
            }
            else{
                while(st.top().first=='&'){
                    tmp+=st.top().second;
                    st.pop();
                }
                if(st.top().first=='['){
                    st.pop();
                    if(tmp){
                        if(!st.empty()){
                            st.push(pair<char, int>('&', tmp*3));
                        } else{
                            ans+=tmp*3;
                        }
                    } else{
                        if(!st.empty()){
                            st.push(pair<char, int>('&', 3));
                        } else{
                            ans+=3;
                        }
                    }
                }else{  //]와 짝이 안맞음
                    ans=0;
                    break;
                }
            }
        }
    }

    if(ans==0){
        cout<<ans;
        return 0;
    }
    if(!st.empty()) //올바르지 않은 괄호열
        ans=0;
    cout<<ans;
}