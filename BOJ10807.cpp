//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int freq[201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, v;
    cin >> n;

    while (n--) {
        cin >> tmp;
        freq[tmp + 100]++;
    }
    cin >> v;
    cout << freq[v + 100];

}
