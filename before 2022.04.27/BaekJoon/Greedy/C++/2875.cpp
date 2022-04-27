//2021.12.14
#include<iostream>
using namespace std;

int n, m, k;

int main(){
    cin >> n >> m >> k;
    int sum = 0;
    while(n+m >= k){
        if(n < 2 || m < 1) break;
        sum += 1;
        n -= 2;
        m -= 1;
        if(n+m < k) {
            n += 2; m += 1; sum -= 1;
            break;
        }
    }
    cout << sum;
}