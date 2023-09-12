//2023-09-11.
#include "bits/stdc++.h"

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) cout << '*';
        for (int j = 0; j < 2 * (n - i); j++) cout << ' ';
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) cout << '*';
        for (int j = 0; j < 2 * (n - i); j++) cout << ' ';
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }
}