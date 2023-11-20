#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;	//10이상 1000이하
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int tmp = i;
        string s;
        while (tmp / 10 != 0) {
            int r = tmp % 10;
            if (r == 3 || r == 6 || r == 9) {
                s += to_string(r) + '-';
            }
            else {
                s += to_string(r) + '0';
            }
            tmp/=10;
        }
        if (tmp == 3 || tmp == 6 || tmp == 9) {
            s += to_string(tmp)+'-';
        }
        s += ' ';
        cout << s;
    }
    return 0;
}