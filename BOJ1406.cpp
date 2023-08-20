//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> L;
    for (char c: s)
        L.push_back(c);
    auto cursor = L.end();

    int m;
    cin >> m;

    while (m--) {
        char command;
        cin >> command;
        switch (command) {
            case 'L':
                if (cursor != L.begin())
                    --cursor;
                break;
            case 'D':
                if (cursor != L.end())
                    ++cursor;
                break;
            case 'B':
                if (cursor != L.begin()) {
                    cursor = L.erase(--cursor);
                }
                break;
            case 'P':
                char i;
                cin >> i;
                L.insert(cursor, i);
                break;

        }
    }
    for (auto iter = L.begin(); iter != L.end(); iter++)
        cout << *iter;
}
