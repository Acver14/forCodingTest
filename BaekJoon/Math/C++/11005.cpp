//2021.08.04
#include<iostream>

using namespace std;

int main(){
    int n, b;

    cin >> n >> b;

    string ans = "";
    if(n==0) {
        cout << 0 << '\n';
        return 0;
    }
    while(n){
        if(n%b == 0){
            ans = '0' + ans;
            n = n/b;
        }
        else if(n%b > 9){
            ans = char('A' + (n%b-10)) + ans;
            n = n/b;
        }
        else{
            ans = to_string(n%b) + ans;
            n = n/b;
        }
    }

    cout << ans;
}