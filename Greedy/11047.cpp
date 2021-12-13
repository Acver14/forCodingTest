//2021.12.13
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<int> a;
int ans = 0;

void greedy(){
    int left = k;
    while(left != 0){
        for(int i =0 ; i < n; i++){
            if(left >= a[i]) {
                left -= a[i];
                ans++;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;
    a.resize(n);
    for(int i = n-1; i > -1; i--){
        cin >> a[i];
    }
    greedy();
    cout << ans;
}