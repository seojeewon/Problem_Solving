//2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int D[5000006];

int findMin(deque<int> &dq, int start, int end){
    int min = 1000000003;
    for(auto iter = dq.begin()+start ; iter!=dq.begin()+end+1 ; iter++){
        if(*iter<min)
            min = *iter;
    }
    return min;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, tmp;
    cin >> n >> l;

    deque<int> dq;
    for (int i = 0; i < n; i++) {   // A 입력
        cin >> tmp;
        dq.push_back(tmp);
    }

    for (int i = 1; i <= n; i++) {
        if (i - l + 1 >= 0) {
            //D[i] = *min_element(dq.begin() + (i - l + 1), dq.begin() + (i+1));
            D[i]= findMin(dq, i-l+1, i);
        } else {
            D[i] = findMin(dq, 0, i);
        }
        cout << D[i] << ' ';
    }
}