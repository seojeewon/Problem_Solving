//2023-08-28.
//next_permutation으로 nPr 하는 방법
#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<int> board(10,0);

void func() {
    do {
        for (int i = 0; i < m; i++) {
            cout<<board[i]<<' ';
        }
        cout << '\n';
        //1234 다음에 1243이 나옴. 근데 12를 이미 썼기 때문에 그럴 필요가 없음 따라서 뒤에 애들을 바꾼다.
        reverse(board.begin()+m, board.begin()+n);
    } while (next_permutation(board.begin(), board.begin()+n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<10;i++)
        board[i]=i+1;
    cin >> n >> m;
    func();
}
