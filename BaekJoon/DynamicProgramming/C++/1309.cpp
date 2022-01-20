//2021.08.09
#include<iostream>
using namespace std;

int main(){
    long long D[100001][3];
    int n;
    int mod = 9901;
    cin >> n;

    D[0][0] = 1;
    D[0][1] = 1;
    D[0][2] = 1;

    for(int i = 1; i < n; i++){
        D[i][0] = (D[i-1][0] + D[i-1][1] + D[i-1][2])%mod;
        D[i][1] = (D[i-1][0] + D[i-1][2])%mod;
        D[i][2] = (D[i-1][0] + D[i-1][1])%mod;
    }

    cout << (D[n-1][0] + D[n-1][1] + D[n-1][2])%mod;
}