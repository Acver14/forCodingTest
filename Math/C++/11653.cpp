//2021.08.04
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n > 1){
        for(int i = 2; i <= n; i++){
            if(n%i == 0){
                n /= i;
                cout << i << '\n';
                break;
            }
        }
    }
}