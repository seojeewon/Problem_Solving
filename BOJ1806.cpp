//2023-10-06.
#include "bits/stdc++.h"

using namespace std;
int n, s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    vector<int> a(n, 0); //수열
    for (int i = 0; i < n; i++) cin >> a[i];
    int en = 0;
    int min = 1000000;    //가장 짧은 길이
    int sum = a[0];
    for (int st = 0; st < n; st++) {
        while (en < n && sum < s) {
            en++;
            sum += a[en];
        }
        if (en == n) break;
        if (en - st + 1 < min) min = en - st + 1;
        sum -= a[st];
    }
    if (min == 1000000) {   //합을 만드는 것이 불가능
        cout << 0;
        return 0;
    }
    cout << min;
}