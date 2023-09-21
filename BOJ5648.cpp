//2023-09-13.
#include "bits/stdc++.h"

using namespace std;
int n;

vector<long long> func(vector<string> &o) {
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        if (o[i].size() == 1) v.push_back(o[i][0] - '0');
        else {
            string tmp = o[i];
            long long a = tmp[0] - '0';
            for (int j = 1; j < tmp.size(); j++) {
                long long m = 1;
                for (int k = 0; k < j; k++) m *= 10;
                a += (tmp[j] - '0') * m;
            }
            v.push_back(a);
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> o(n);
    for (int i = 0; i < n; i++)cin >> o[i];
    vector<long long> v = func(o);
    sort(v.begin(), v.end());
    for (long long l: v) cout << l << '\n';
}
