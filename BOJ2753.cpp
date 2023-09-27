//2023-09-26.
#include "bits/stdc++.h"

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;
    cin>>year;
    if(year%4!=0){
        cout<<0;
        return 0;
    }
    if(year%100!=0){
        cout<<1;
        return 0;
    }
    if(year%400==0){
        cout<<1;
        return 0;
    }
    cout<<0;
}