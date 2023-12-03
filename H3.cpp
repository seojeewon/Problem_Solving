#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;
string board[12];
bool vis[12][12];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin>>m>>n;

    for(int i=0;i<n;i++){
        cin>>board[i];
    }


}