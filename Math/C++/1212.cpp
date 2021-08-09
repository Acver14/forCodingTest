//2021.08.03
#include<iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    string ans = "";
    
    for(char ch: str){
        string ansTemp = "";
        if(ch == '0'){
            ansTemp = "000";
            ans += ansTemp;
            continue;
        }
        int temp = ch - '0';
        while(temp / 2 != 0){
            if(temp % 2 == 1) ansTemp = '1' + ansTemp;
            else ansTemp = '0' + ansTemp;
            temp = temp/2;
        }
        ansTemp = '1' + ansTemp;
        while(ansTemp.length() != 3) ansTemp = '0' +ansTemp;
        ans += ansTemp;
    }

    while(ans[0] == '0' && ans.length() > 1){
        ans = ans.erase(0, 1);
    }
    cout << ans;
}