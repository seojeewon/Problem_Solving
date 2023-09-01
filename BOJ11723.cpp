//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
int arr[21];
int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    string s;
    int x;
    while (m--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            arr[x] = 1;
        } else if (s == "remove") {
            cin >> x;
            arr[x] = 0;
        } else if (s == "check") {
            cin >> x;
            if (arr[x]) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (s == "toggle") {
            cin >> x;
            if (arr[x]) arr[x] = 0;
            else arr[x] = 1;
        } else if (s == "all") {
            fill(arr, arr + 21, 1);
        } else {
            fill(arr, arr + 21, 0);
        }
    }
}