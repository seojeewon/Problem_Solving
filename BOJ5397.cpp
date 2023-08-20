//2023-08-20.
#include "bits/stdc++.h"

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    string s;
    cin >> T;

    list<char> L;
    while (T--) {
        cin >> s;
        L.erase(L.begin(), L.end());
        auto cursor = L.end();
        for (char c: s) {
            switch (c) {
                case '<':
                    if (cursor != L.begin()) {
                        --cursor;
                    }
                    break;
                case '>':
                    if (cursor != L.end()) {
                        ++cursor;
                    }
                    break;
                case '-':   //||로 했을 때 런타임 에러남->ㅇㅇ empty가 아니고 시작하면 안되지
                    if (!L.empty() && (cursor != L.begin())) {
                        cursor = L.erase(--cursor);
                    }
                    break;
                default:
                    L.insert(cursor, c);
                    break;

            }

        }

        for (auto iter = L.begin(); iter != L.end(); iter++)
            cout << *iter;
        cout << '\n';
    }
}