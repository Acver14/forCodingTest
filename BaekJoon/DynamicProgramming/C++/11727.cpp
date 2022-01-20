//2021.07.20
#include<iostream>
using namespace std;

long D[1001] = {0, };
int MOD = 10007;

int main(){
    D[1] = 1;
    D[2] = 3;
    D[3] = 5;

    int n = 0;

    cin >> n;

    for(int i = 4; i <= n; i++){
        D[i] = (D[i-1] + D[i-2] * 2) % MOD;
    }

    cout << D[n] << '\n';
    return 0;
}
