//2021.07.22
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = n; i > 0; i--){
        for(int j = 1; j <= n; j++){
            if(j < i) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    for(int i = n-1; i > 0; i--){
        for(int j = n; j > 0; j--){
            if(j > i) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}