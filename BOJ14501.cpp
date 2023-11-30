//2023-11-20.
#include <iostream>
#include <algorithm>

using namespace std;
int t[17];  //소요되는 시간
int p[17];  //금액
int d[17];  //i번째 일에 상담했을 때 얻을 수 있는 최대 이익
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    //입력
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--) {
        //i번째 날짜에 일을 시작할 수 있음
        if (i + t[i] <= n + 1) {
            //일을 했을 때랑 안했을 때 비교해서 더 큰거
            d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
        }
            //i번째 날짜에 일을 시작할 수 없음
        else {
            d[i] = d[i + 1];
        }
    }

    cout << *max_element(d, d + n + 1);
}
