//2023-09-10.
#include "bits/stdc++.h"

using namespace std;
int n, m;
int board[55][55];
int calc(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<tuple<int, int, int>> chicken;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                chicken.push_back({i, j, 0});
                board[i][j] = 0;
            }
        }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(board[i][j]!=1) continue;
            int locMin=0;
            for(int k=0;k<chicken.size();k++)

            calc({i,j}, )
        }
    }
}