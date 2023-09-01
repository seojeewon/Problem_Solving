//2023-08-31.
#include "bits/stdc++.h"

using namespace std;
map<string, string> M;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string site, pw;
    for (int i = 0; i < n; i++) {
        cin >> site >> pw;
        M[site] = pw;
    }
    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << M[site] << '\n';
    }
}