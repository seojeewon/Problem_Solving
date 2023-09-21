//2023-09-17.
#include "bits/stdc++.h"

using namespace std;
int cntZero = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    for (int i = 0; i < 3; i++) {
        cntZero = 0;
        for (int j = 0; j < 4; j++) {
            cin >> input;
            if (!input) cntZero++;
        }
        switch (cntZero) {
            case 0:
                cout << "E\n";
                break;
            case 1:
                cout << "A\n";
                break;
            case 2:
                cout << "B\n";
                break;
            case 3:
                cout << "C\n";
                break;
            default:
                cout << "D\n";
        }
    }

}
