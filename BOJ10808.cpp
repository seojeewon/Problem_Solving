//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int alphabet[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    for (char c: word) {
        alphabet[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        cout << alphabet[i] << ' ';
}