//2023-09-05.
#include "bits/stdc++.h"

using namespace std;
int a, b, c;
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    int result = a * b * c;
    while (result) {
        arr[result % 10]++;
        result /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << '\n';
}
