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
    int a, b, m;

    cin >> a >> b;

    cin >> m;

    int temp = 0;
    for(int i = m-1; i > -1; i--){
        int n;
        cin >> n;
        temp += n * _pow(a, i);
    }

    string ans = "";
    while(temp){
        ans = to_string(temp%b) + ans;
        temp /= b;
        if(temp) ans = ' ' + ans;
    }

    cout << ans;
}