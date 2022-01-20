//2022.01.18
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s, m, n;
int a[1001];
int b[1001];
vector<long long> va;
vector<long long> vb;

void go(int last, vector<long long> &x, int *arr){
    x.push_back(0);
    for(int i = 0; i < last; i++){
        int j = i;
        int end = (i+last-1)%last;
        long long sum = 0;
        while(j != end){
            sum += arr[j];
            if(sum <= s)x.push_back(sum);
            else break;
            j++;
            if(j >= last) j = 0;
        }
        if(i == 0){
            sum += arr[end];
            x.push_back(sum);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    go(m, va, a);
    go(n, vb, b);

    sort(va.begin(), va.end());

    long long ans = 0;
    for(long long i: vb){
        auto up = upper_bound(va.begin(), va.end(), (s-i));
        auto low = lower_bound(va.begin(), va.end(), (s-i));
        ans += up - low;
    }

    cout << ans;
}