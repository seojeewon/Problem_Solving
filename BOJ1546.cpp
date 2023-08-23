//2023-08-23.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<double> v(n, 0.0);
    for (int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        v[i]=(double)tmp;
    }
    sort(v.begin(), v.end());
    double max = v[n - 1];
    for (int i = 0; i < n; i++) {
        v[i] = v[i] / max * 100.0;
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    cout << sum / (double) n;
}