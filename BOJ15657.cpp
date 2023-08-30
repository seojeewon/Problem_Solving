//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int v[10];  //처음에 주어진 수열
int arr[10];    //길이가 m인 수열 저장
void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((k == 0) || (arr[k - 1] <= v[i])) {
            arr[k] = v[i];
            func(k + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n);
    func(0);
}
