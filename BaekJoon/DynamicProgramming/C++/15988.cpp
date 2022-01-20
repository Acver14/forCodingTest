//2021.08.09
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    int mod = 1000000009;

    long long D[1000001] = {0,};
    D[0] = 1;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 4; j <= n; j++){
            if(D[j] == 0) D[j] = (D[j-3] + D[j-2] + D[j-1])%mod;
        }
        cout << D[n]%mod << '\n';
    }
}