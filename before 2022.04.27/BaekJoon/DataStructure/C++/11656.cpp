//2021.08.02
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    string str;
    vector<string> v;

    cin >> str;
    int len = str.length();
    for(int i = 0; i < len; i++){
        v.push_back(str.substr(i, len));
    }

    sort(v.begin(), v.end());

    for(const auto &item: v){
        cout << item << '\n';
    }
}