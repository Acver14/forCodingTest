//2021.08.04
#include<iostream>

using namespace std;

int main(){
    int n;
    string result = "";
    cin >> n;

    if(n==0) cout << 0;

    while(n != 0){
        if(n%(-2)){
            result = '1' + result;
            n = (n-1)/(-2);
        }else{
            result = '0' + result;
            n /= (-2);
        }
    }

    cout << result;
}