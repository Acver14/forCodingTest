//2021.08.02
#include<iostream>

using namespace std;

int main(){
    string str;
    int pos[26] = {0, };

    cin >> str;

    fill_n(pos, 26, -1);

    for(int i = 0; i < str.length(); i++){
        if(pos[str[i]-'a'] < 0){
            pos[str[i]-'a'] = i;
        }
    }

    for(int i = 0; i < 26; i++){
        cout << pos[i] << ' ';
    }
}