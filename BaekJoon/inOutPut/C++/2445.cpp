//2021.07.22
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n; j++){
            if(i >= j || 2 * n - i + 1 <= j) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    for(int i = n-1; i > 0; i--){
        for(int j = 1; j <= 2 * n; j++){
            if(i >= j || 2 * n - i + 1 <= j) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}