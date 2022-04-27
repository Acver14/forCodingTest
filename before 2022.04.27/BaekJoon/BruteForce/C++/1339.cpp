//2021.09.16
#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str[10];
    int value[26] = {0, };
    int cnt[8][26];
    int ctoi[26] = {0, };
    bool check_int[10] = {false, };
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < n; i++){
        cin >> str[i];
        int len = str[i].length();
        for(int j = 0; j < len; j++){
            cnt[len-j-1][str[i][j]-'A']++;
        }
    }

    for(int i = 7; i > -1; i--){
        for(int j = 0; j < 26; j++){
            value[j] += pow(10, i)*cnt[i][j];
        }
    }
    int val_int = 9;
    for(int i = 9; i > -1; i--){
        if(check_int[i]) continue;
        int max = 0;
        int idx = -1;
        for(int j = 0; j < 26; j++){
            if(max < value[j]){
                max = value[j];
                idx = j;
            }
        }
        if(idx != -1){
            check_int[i] = true;
            ctoi[idx] = val_int--;
            value[idx] = 0;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int len = str[i].length();
        for(int j = 0; j < len; j++){
            str[i][j] = '0' + (ctoi[str[i][j]-'A']);
        }
        ans += stoi(str[i]);
    }
    cout << ans;
}