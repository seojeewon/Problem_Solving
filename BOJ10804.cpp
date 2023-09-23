//2023-09-22.
#include "bits/stdc++.h"

using namespace std;
vector<int> arr(21, 0);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 21; i++) arr[i] = i;
    int test = 10;
    while (test--) {
        int start, end;
        cin >> start >> end;
        reverse(arr.begin() + start, arr.begin() + (end + 1));
    }
    for (int i = 1; i < 21; i++) cout << arr[i] << ' ';
}
