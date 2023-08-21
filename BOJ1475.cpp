//2023-08-21.

#include "bits/stdc++.h"

using namespace std;

int num[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (char c: s) {
        num[c - '0']++;
    }
    int sum = (num[6] + num[9]);
    num[6] = sum / 2;
    num[9] = sum - num[6];

    cout << *max_element(num, num + 10);
}