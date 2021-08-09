//2021.07.16
#include <iostream>
using namespace std;
long D[101][11] = {0, };
#define MOD 1000000000;


int main(){
    int n;
    cin >> n;

    for(int i = 1; i < 10; i++){
        D[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        D[i][0] = (D[i-1][1]) % MOD;
        D[i][9] = (D[i-1][8]) % MOD;
        for(int j = 1; j < 9; j++){
            D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % MOD;
        }
    }

    long ans[101] = {0, };
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10; j++){
            ans[i] += D[i][j];
        }
    }

    cout << ans[n] % MOD;

    return 0;
}