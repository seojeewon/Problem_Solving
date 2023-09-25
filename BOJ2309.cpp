//2023-09-24.
/**
 * 문제 idea: 조합을 사용해서 9명 중 7명을 선택하고,
 * 7명 키의 합이 100이 되면 출력(조건: 여러 가지면 아무거나 출력)
 */
#include "bits/stdc++.h"

using namespace std;
int dwarf[9];   //난쟁이
int arr[7]; //선택된 난쟁이를 담는 배열
int tmp[9];

int sum() {
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans += arr[i];
    }
    return ans;
}

void choice() {
    fill(tmp + 7, tmp + 9, 1);

    do {
        int idx = 0;
        for (int i = 0; i < 9; i++) {
            if (tmp[i] == 1) continue;
            arr[idx++] = dwarf[i];
        }
        if (sum() == 100) return;
    } while (next_permutation(tmp, tmp + 9));
}

void choice2(){
    int ar[4]={3,2,4,5};
    do{
        for(int i=0;i<4;i++)
            cout<<ar[i]<<' ';
        cout<<'\n';
    }while(next_permutation(ar, ar+4));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    choice2();

    /*for (int i = 0; i < 9; i++)
        cin >> dwarf[i];
    choice();
    sort(arr, arr + 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << '\n';
    }*/
}
