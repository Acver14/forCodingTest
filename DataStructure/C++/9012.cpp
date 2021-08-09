//2021.07.27
#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        string str;
        int cnt = 0;
        cin >> str;
        for(char ch: str){
            if(ch == '(') cnt++;
            else cnt--;
            if(cnt < 0) break;
        }
        if(cnt == 0){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}