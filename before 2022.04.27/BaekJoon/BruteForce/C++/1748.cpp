//2021.08.18
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, cnt = 0;
    cin >> n;
    int N = n;
    int ans = 0;
    while(N > 9){
        N/=10;
        cnt++;
    }
    for(int i = 0; i < cnt; i++){
        ans += 9 * pow(10, i) * (i+1);
    }
    ans += (n-(int)pow(10, cnt)+1) * (cnt+1);

    cout << ans;
}