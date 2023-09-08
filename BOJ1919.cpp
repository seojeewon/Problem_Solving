//2023-09-07.
#include "bits/stdc++.h"

using namespace std;
int first[26], second[26], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    for (char a: s1) first[a - 'a']++;
    for (char a: s2) second[a - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (first[i] == second[i]) continue;
        ans += abs(first[i] - second[i]);
    }
    cout << ans;
}
