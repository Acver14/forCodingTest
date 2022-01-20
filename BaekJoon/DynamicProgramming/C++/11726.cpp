//2021.07.15
#include <iostream>
using namespace std;
int D[1003];
#define MOD 10007;


int main(){
    int n;
    cin >> n;

    D[0] = 0;
    D[1] = 1;
    D[2] = 2;

    for (int i = 3; i <= n; i++){
        D[i] = (D[i-1] + D[i-2]) % MOD;
    }

    cout << D[n];
    return 0;
}