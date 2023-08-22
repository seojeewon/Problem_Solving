//2023-08-21.

#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    string s;

    cin >> n;

    while (n--) {
        stack<char> st;
        cin >> s;
        if (s.size() % 2) continue;    //단어의 길이가 홀수면 좋은 단어x-짝을 지을 수 없는 글자가 반드시 생기기 때문
        for (char c: s) {
            if (st.empty() || st.top() != c)
                st.push(c);
            else {
                if (st.top() == c)
                    st.pop();
                else
                    break;
            }
        }
        if (!st.empty()) continue;
        ans++;
    }
    cout << ans;
}
