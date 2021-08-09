//2021.07.23
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            if(i <= j && 2*n-i-1 > j) cout << '*';
            else if(2 * n - i <= j) break;
            else cout <<' ';
        }
        cout << '\n';
    }
    for(int i = n-2; i > -1; i--){
        for(int j = 0; j < 2 * n - 1; j++){
            if(i <= j && 2*n-i-1 > j) cout << '*';
            else if(2 * n - i <= j) break;
            else cout <<' ';
        }
        cout << '\n';
    }
    return 0;
}