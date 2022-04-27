//2021.08.03
#include<iostream>

using namespace std;

int main(){
    string str;
    string ans = "";

    cin >> str;

    while(str.length() % 3 != 0) str = '0' + str;
    int len = str.length();
    
    for(int i = 0; i < len; i+=3){
        int tmp = 0;
        if(str[i] == '1') tmp += 4;
        if(str[i+1] == '1') tmp += 2;
        if(str[i+2] == '1') tmp += 1;
        ans += to_string(tmp);
    }

    cout << ans;
}