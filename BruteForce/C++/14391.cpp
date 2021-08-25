//2021.08.25
#include<iostream>
using namespace std;

int main(){
    int n, m;
    char a[4][4];
    char v[16];
    char z = '0';
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            v[i*m+j] = a[i][j];
        }
    }

    for(int i = 0; i < n*m; i++){
        cout << v[i] << ' ';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

        }
    }
}