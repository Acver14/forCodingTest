//2021.08.25
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>  v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 1; i < (1 << n); i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                sum += v[j];
            }
        }
        if(sum == k) ans++;
    }
    cout << ans;
}