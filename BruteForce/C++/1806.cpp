//2022.01.12
#include<iostream>
#include<algorithm>
using namespace std;

int n, s;
int a[100000];
int ans = 100000001;

int min(int a, int b){
    if (a < b) return a;
    return b;
}

void solve(){
    int low = 0, high = 0;
    int sum = a[0];

    while (low <= high && high < n)
    {
        if (sum < s)
                sum += a[++high];
        else if (sum == s)
        {
                ans = min(ans, (high - low + 1));
                sum += a[++high];
        }
        else if (sum > s)
        {
                ans = min(ans, (high - low + 1));
                sum -= a[low++];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    solve();
    if(ans == 100000001)cout << 0;
    else cout << ans;
}