//2023-10-14.
#include "bits/stdc++.h"
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1 = "This is Jiwon.";
    string s2 = "this/is/not/me";

    istringstream ss1(s1);
    istringstream ss2(s2);

    string buffer;
    vector<string> v1, v2;
    while(getline(ss1, buffer, ' ')){
        v1.push_back(buffer);
    }
    while(getline(ss2,buffer,'/')){
        v2.push_back(buffer);
    }

    for(int i=0;i<v1.size();i++){
        cout<<i<<"th: "<<v1[i]<<' ';
    }
    for(int i=0;i<v2.size();i++){
        cout<<i<<"th: "<<v2[i]<<' ';
    }
}
