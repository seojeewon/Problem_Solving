//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int freq[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string a, b;

    while (n--) {
        //0으로 초기화
        fill(freq, freq + 26, 0);
        cin >> a >> b;
        for (char c: a) {
            freq[c - 'a']++;
        }
        for (char c: b) {
            freq[c - 'a']--;
        }

        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";

    }

}
