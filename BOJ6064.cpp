//2023-08-30.
#include "bits/stdc++.h"

using namespace std;
int t, m, n, x, y, g;   //g는 최소공배수
int func1(int a1, int a2) {  //최대공약수 구하기
    if (a1 == 1) return 1;
    if (a1 == a2) return a1;
    if (a1 < a2 - a1) return func1(a1, a2 - a1);
    else return func1(a2 - a1, a1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> m >> n >> x >> y;
        if (m == n) {
            g = m;
            cout << x << '\n';
            continue;
        } else if (m < n) {
            g = m * n / func1(m, n);
            if(x==m&&y==n){
                cout<<g<<'\n';
                continue;
            }
            int k = 0;
            while (true) {
                if ((n * k) + (y % n) > g) {
                    cout << -1 << '\n';
                    break;
                }
                if (((n * k) + (y % n)) % m == x % m) {
                    cout << (n * k) + (y % n) << '\n';
                    break;
                }
                k++;
            }
        } else {
            g = m * n / func1(n, m);
            if(x==m&&y==n){
                cout<<g<<'\n';
                continue;
            }
            int k = 0;
            while (true) {
                if ((m * k) + (x % m) > g) {
                    cout << -1 << '\n';
                    break;
                }
                if (((m * k) + (x % m)) % n == y % n) {
                    cout << (m * k) + (x % m) << '\n';
                    break;
                }
                k++;
            }
        }
    }
}
