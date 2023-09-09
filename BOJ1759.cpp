//2023-09-09.
#include "bits/stdc++.h"

using namespace std;
int l, c;
char abc[20];
bool vis[20];
char arr[20];

bool check() {
    int numMo = 0, numJa = 0;
    for (int i = 0; i < l; i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            numMo++;
    }
    numJa = l - numMo;
    if (numMo < 1 || numJa < 2) return false;
    return true;
}

void func(int k) {
    if (k == l) {
        if (!check()) return;
        for (int i = 0; i < l; i++) cout << arr[i];
        cout << '\n';
        return;

    }
    for (int i = 0; i < c; i++) {
        if (vis[i] || abc[i] < arr[k - 1]) continue;
        vis[i] = 1;
        arr[k] = abc[i];
        func(k + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> abc[i];
    sort(abc, abc + c);
    func(0);
}