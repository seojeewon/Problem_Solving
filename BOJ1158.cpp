//요세푸스 문제-2023-08-20.
#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> L;
    for (int i = 1; i < n + 1; i++)
        L.push_back(i);

    auto iter = L.begin();
    cout << '<';
    while (L.size() != 1) {
        for (int i = 0; i < k - 1; i++){
            if(++iter==L.end())
                iter=L.begin();
        }
        cout << *iter << ", ";
        iter = L.erase(iter);
        if(iter==L.end())
            iter=L.begin();
    }
    cout << L.front() << ">";

}
