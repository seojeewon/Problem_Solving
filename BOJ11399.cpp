//2023-09-01.
#include "bits/stdc++.h"

using namespace std;
int n;
int ppl[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)cin >> ppl[i];
    sort(ppl, ppl + n);
    for (int i = 1; i < n; i++)
        ppl[i] = ppl[i - 1] + ppl[i];
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ppl[i];
    cout << sum;
}
