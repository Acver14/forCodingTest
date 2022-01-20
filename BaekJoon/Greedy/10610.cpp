//2021.12.14
#include<iostream>
#include<algorithm>
using namespace std;

bool comp(char a, char b){
    if (a > b) return true;
    return false;
}

string s;

int main(){
    cin >> s;

    sort(s.begin(), s.end(), comp);
    
    long long ansCheck = 0;

    for(char c: s){
        ansCheck += c-'0';
    }
    if(ansCheck%3 == 0 && s.back() == '0'){
        cout << s;
    }
    else cout << -1;
}