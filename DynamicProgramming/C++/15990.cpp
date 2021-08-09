//2021.08.06
#include<iostream>
using namespace std;

#define MOD 1000000009

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    long long N[100001][4] = {0, };

    cin >> t;

    N[1][1] = 1;
    N[1][2] = N[1][3] = 0;
    N[2][1] = 0;
    N[2][2] = 1;
    N[2][3] = 0;
    N[3][1] = 1;
    N[3][2] = 1;
    N[3][3] = 1;


    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 4; j <= n; j++){
            if(N[j][1] != 0) continue;
            N[j][1] = (N[j-1][2] % MOD + N[j-1][3] % MOD) % MOD;
            N[j][2] = (N[j-2][1] % MOD + N[j-2][3] % MOD) % MOD;
            N[j][3] = (N[j-3][2] % MOD + N[j-3][1] % MOD) % MOD;
        }
        cout << (N[n][1] + N[n][2] + N[n][3]) % MOD << '\n';
    }
}