//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
int x = 1, y = 1;



void func(int n, int m) {
    if (n == 1) {
        if (m == 1) {
            cout << x << ' ' << y;
        } else if (m == 2) {
            cout << x << ' ' << y + 1;
        } else if (m == 3) {
            cout << x + 1 << ' ' << y + 1;
        } else {
            cout << x + 1 << ' ' << y;
        }
        return;
    }
    int pre = 1 << (2 * n - 2);
    if (m <= pre) {
        func(n - 1, m);
    } else if (m > pre && m <= pre * 2) {
        y += 1 << (n - 1);
        func(n - 1, m - pre);
    } else if (m > pre * 2 && m <= pre * 3) {
        x += 1 << (n - 1);
        y += 1 << (n - 1);
        func(n - 1, m - pre * 2);
    } else {
        x += 1 << (n - 1);
        func(n - 1, m - pre * 3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;   //size of square, # of meter-steps
    cin >> n >> m;

    func(n, m);
}
