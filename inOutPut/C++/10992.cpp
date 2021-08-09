//2021.07.23
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < 2 * n - 1; j++){
            if(j == i || j == 2 * n - i - 2) cout <<'*';
            else if(j > 2 * n - i - 2) break;
            else cout << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < 2 * n - 1; i++) cout << "*";
    return 0;
}