//2021.01.11
#include<iostream>
using namespace std;

int a[10000];
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += a[j];
            if(sum > m) break;
            if(sum == m) ans++;
        }
    }
    cout << ans;
}