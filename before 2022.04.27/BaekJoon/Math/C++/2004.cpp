//2021.08.03
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    long long cnt2 = 0;
    long long cnt5 = 0;

    for(long long i = 2; i <= n; i*=2){
        cnt2 += n/i;
    }
    for(long long i = 2; i <= n-m; i*=2){
        cnt2 -= (n-m)/i;
    }
    for(long long i = 2; i <= m; i*=2){
        cnt2 -= m/i;
    }
    for(long long i = 5; i <= n; i*=5){
        cnt5 += n/i;
    }
    for(long long i = 5; i <= n-m; i*=5){
        cnt5 -= (n-m)/i;
    }
    for(long long i = 5; i <= m; i*=5){
        cnt5 -= m/i;
    }

    if(cnt2 < cnt5) cout << cnt2;
    else cout << cnt5;
}