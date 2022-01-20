//2022.01.19
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long t;
int n, m;
int a[1001], b[1001];
vector<long long> va, vb;

void go(int last, int *arr, vector<long long> &x){
    for(int i = 0; i < last; i++){
        long long sum = 0;
        for(int j = i; j < last; j++){
            sum += arr[j];
            x.push_back(sum);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    go(n, a, va);
    go(m, b, vb);

    sort(va.begin(), va.end());

    long long ans = 0;
    for(long long i: vb){
        auto up = upper_bound(va.begin(), va.end(), (t-i));
        auto low = lower_bound(va.begin(), va.end(), (t-i));
        ans += up - low;
    }
    cout << ans;
}