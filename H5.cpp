#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> kDomain;
unordered_map<string, string> k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        string cmd;
        getline(cin, cmd);
        if(cmd.empty()) break;
        if(cmd=="R"){
            string domain;
            cin>>domain;
            string ip;
            cin>>ip;
            kDomain[domain]=ip;
        }
        else if(cmd=="S"){
            string c;
            cin>>c;
            if()
        }
        else{
            cout<<3<<'\n';
        }
    }
}