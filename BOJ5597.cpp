//2023-09-03.
#include "bits/stdc++.h"

using namespace std;
int stu[31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for (int i = 0; i < 28; i++) {
        cin >> t;
        stu[t] = 1;
    }
    for (int i = 1; i < 31; i++)
        if (!stu[i]) cout << i << '\n';
}
