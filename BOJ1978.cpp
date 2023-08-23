//2023-08-23.
#include "bits/stdc++.h"

using namespace std;
bool num[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, ans = 0;
    cin >> n;

    fill(num, num + 1001, true);
    num[1] = false;
    for (int i = 2; i < 1001; i++) {
        if(!num[i]) continue;
        for(int j=i ; j*i<1001 ; j++){
            num[i*j]=false;
        }
    }
    while (n--) {
        cin >> tmp;
        if (num[tmp])
            ans++;
    }
    cout << ans;


}
