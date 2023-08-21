//2023-08-21.
/**
 * 쇠막대 문제
 * 쇠막대와 레이저의 차이: 레이저는 바로 직전에 (가 나옴
 * 레이저로 잘랐을 때: 스택높이만큼의 조각이 생김
 * 쇠막대가 끝났을 때: 1조각이 더 생김
 */

#include "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char pre = ' ';
    string s;
    int ans = 0;
    stack<char> st;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            st.push(s[i]);
            pre = s[i];
            continue;
        }
        if (pre == '(' && s[i] == ')') {   //레이저
            st.pop();
            ans += st.size(); //스택 높이만큼 조각이 생김
        } else if (pre == ')' && s[i] == ')') { //쇠막대 끝남
            st.pop();
            ans++;
        } else {   //s[i]가 (인 경우
            st.push(s[i]);
        }
        pre = s[i];
    }

    cout << ans;
}
