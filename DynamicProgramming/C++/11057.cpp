//2021.07.20
#include<iostream>
using namespace std;

int D[1001][10] = {{0, }};

int main(){
    int n;

    cin >> n;
    for(int i = 0; i < 10; i++){
        D[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                D[i][j] += D[i-1][k];
            }
            D[i][j] %= 
            10007;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++){
        ans += D[n][i];
    }
    cout << ans % 10007;
    return 0;
}