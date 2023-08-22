//2023-08-22.
/**
 * 1제곱을 계산할 수 있다.
 * k제곱을 계산했으면 2k제곱과 2k+1제곱도 O(1)에 계산할 수 있다.
 * 모듈러 연산의 성질
 */
#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int func(ll a, ll b, ll c) {
    if (b == 1) {
        return a % c;
    }
    ll val = func(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << func(a, b, c);
}