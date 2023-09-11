//2023-09-10.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = n; i > 0; i--) {
        for (int k = 0; k < n - i; k++) cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << '\n';
    }
    for (int i = 2; i <= n; i++) {
        for (int k = 0; k < n - i; k++) cout << ' ';
        for (int j = 0; j < 2 * i - 1; j++)
            cout << '*';
        cout << '\n';
    }

}
