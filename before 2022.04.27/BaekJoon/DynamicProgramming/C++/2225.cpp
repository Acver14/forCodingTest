//2021.08.09
#include<iostream>
using namespace std;

int main(){
    int n, k;
    long long D[201][201];
    cin >> n >> k;

    D[0][0] = 1;

    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int l = 0; l <= j; l++){
                D[i][j] += D[i-1][j-l];
                D[i][j] %= 1000000000;
            }
        }
    }

    cout << D[k][n] % 1000000000;
}