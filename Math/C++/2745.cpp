//2021.08.04
#include<iostream>

using namespace std;

int _pow(long long a, int z){
    int ret = 1;
    for(int i = 0; i < z; i++){
        ret *= a;
    }
    return ret;
}

int main(){
    string n;
    int b;
    long long ans = 0;
    cin >> n >> b;

    int len = n.length() - 1;
    for(char ch: n){
        if(ch >= '0' && ch <= '9'){
            ans += int(ch - '0') * _pow(b, len);
            len -= 1;
        }
        else{
            ans += (int(ch - 'A') + 10) * _pow(b, len);
            len -= 1;
        }
    }

    cout << ans;
}