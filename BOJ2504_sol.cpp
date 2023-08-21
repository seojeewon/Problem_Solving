//2023-08-21.
/**
 * (나 [가 오면 스택에 넣고 num에 2나 3을 곱하기
 * )가 나왔는데 직전에 (가 나왔으면 더해야 하는 상황이니까 sum에 num을 더하고 pop하고 num을 2로 나눈다.
 * [도 마찬가지
 */
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    stack<char> st;
    int num = 1, sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            num *= 2;
            st.push(s[i]);
        } else if (s[i] == '[') {
            num *= 3;
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') sum += num;
            st.pop();
            num /= 2;
        } else { //s[i]=']'
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') sum += num;
            st.pop();
            num /= 3;
        }
    }
    if (!st.empty()) {
        cout << 0;
        return 0;
    }
    cout << sum;
}