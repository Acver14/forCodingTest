//2021.07.22
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = n; i > 0; i--){
        for(int j = 1; j <= 2*n-i; j++){
            if(j < i) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}