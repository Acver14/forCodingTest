//2021.08.02
#include<iostream>

using namespace std;

int main(){
    string str;
    int cnt[26] = {0, };
    cin >> str;

    for(char ch : str){
        cnt[ch-'a']++;
    }

    for(int i = 0; i < 26; i++){
        cout << cnt[i] << ' ';
    }
}