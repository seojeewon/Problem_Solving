//2023-09-30.
#include "bits/stdc++.h"

using namespace std;
int n;
string names[100002];

bool cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[1] == v2[1]) {
        if (v1[2] == v2[2]) {
            if (v1[3] == v2[3]) {
                return names[v1[0]] < names[v2[0]];
            }
            return v1[3] > v2[3];
        }
        return v1[2] < v2[2];
    }
    return v1[1] > v2[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    //vector<string> names(n);
    vector<vector<int>> scores(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names[i] = name;
        scores[i][0] = i;
        cin >> scores[i][1] >> scores[i][2] >> scores[i][3];
    }
    sort(scores.begin(), scores.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << names[scores[i][0]] << '\n';
    }
}
