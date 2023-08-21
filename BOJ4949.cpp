//2023-08-21.

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    stack<char> st;
    while (true) {
        string ans = "yes\n";
        getline(cin, s);
        if (s == ".")  //.들어오면 입력종료
            break;
        for (char c: s) {
            if (c == '(' || c == '[')    //여는 괄호->스택에 넣기
                st.push(c);
            else if (c == ')') {  //닫는 괄호
                if (st.empty() || st.top() != '(') { //stack이 빈 경우에도 오류임->처음에 이걸 놓침
                    ans = "no\n";
                    break;
                } else {
                    st.pop();
                }
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    ans = "no\n";
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (!st.empty()) {
            ans = "no\n";
        }

        cout << ans;
        //stack 비우기
        while (!st.empty())
            st.pop();

    }


}