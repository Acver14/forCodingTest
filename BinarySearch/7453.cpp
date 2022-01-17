//2022.01.17
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long long a[2][4001];
long long c[2][4001];
vector<long long> ab;
vector<long long> cd;

void go(long long arr[2][4001], vector<long long> &x){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            x.push_back(arr[0][i]+arr[1][j]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[0][i] >> a[1][i] >> c[0][i] >> c[1][i];
    }

    dfs(a, ab);
    dfs(c, cd);
    sort(ab.begin(), ab.end());

    long long ans = 0;
    for(long long i: cd){
        auto up = upper_bound(ab.begin(), ab.end(), i*(-1));
        auto low = lower_bound(ab.begin(), ab.end(), i*(-1));
        ans += up - low;
    }

    cout << ans;
}