//2023-08-22.
#include "bits/stdc++.h"

using namespace std;

void makeVector(vector<int> &v, string array) {
    int cnt = 0;
    for (int i = 0; i < array.size(); i++) {
        string tmp = "";
        int num = 0;
        if (array[i] == '[' || array[i] == ']' || array[i] == ',') continue;
        while (i < array.size() && array[i] != '[' && array[i] != ']' && array[i] != ',') {
            tmp += array[i++];
        }
        v[cnt++]=stoi(tmp);
        //v.push_back(stoi(tmp));
    }
}

string makeString(vector<int> &v, int n) {
    string ans = "[";
    for (int i = 0; i < n - 1; i++) {
        ans += to_string(v[i]);
        ans += ",";
    }
    ans += to_string(v[n - 1]);
    ans += ']';

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    string cmd, array;
    cin >> T;

    while (T--) {
        bool flag = true;
        cin >> cmd >> n >> array;
        vector<int> v(n,0);
        makeVector(v, array);
        for (char c: cmd) {
            if (c == 'R') {
                reverse(v.begin(), v.end());
            } else { //c=='D'
                if (v.empty()) {
                    flag = false;
                    break;
                }
                v.erase(v.begin());
            }
        }
        if (!flag) {
            cout << "error\n";
        } else {
            cout << makeString(v, n) << '\n';
        }
    }
}
