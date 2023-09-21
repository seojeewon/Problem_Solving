//2023-09-18.
#include "bits/stdc++.h"

using namespace std;
int t, n, homeX, homeY;
bool cmp(pair<int,int> &p1, pair<int,int>&p2){
    return abs(p1.first-homeX)+abs(p1.second-homeY)<abs(p2.first-homeX)+abs(p2.second-homeY);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    int convX, convY, destX, destY;
    while (t--) {
        cin >> n; //편의점 개수
        vector<pair<int,int>> conv(n);
        cin >> homeX >> homeY;  //집 위치
        for (int i = 0; i < n; i++) {   //편의점 위치
            cin >> convX >> convY;
            conv.push_back({convX, convY});
        }
        sort(conv.begin(), conv.end(), cmp);
        //목적지
        cin >> destX >> destY;

    }

}
