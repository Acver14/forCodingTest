//2022.01.14
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n, s;
long long a[40];
long long ans = 0;
vector<long long> l, r; 

void go(int i, int last, long long sum, vector<long long> &x) {
    if (i == last) {
        x.push_back(sum);
        return;
    }
    go(i + 1, last, sum + a[i], x);
    go(i + 1, last, sum, x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> s;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    go(0, n / 2 + 1, 0, l);
    go(n / 2 + 1, n, 0, r);

    sort(r.begin(), r.end());

    for (long long i: l) {
        auto low = lower_bound(r.begin(), r.end(), s - i);
        auto up = upper_bound(r.begin(), r.end(), s - i);
        ans += up - low;
    }

    if(s==0) ans--;
    cout << ans;
}