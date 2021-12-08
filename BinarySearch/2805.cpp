//2021.12.08
#include<iostream>
#include<vector>
using namespace std;

long m, n;
vector<long> a;
long lo = 0;
long hi = 0;
long ans = -1;

void bis(){
    while(lo <= hi){
        long mid = (lo + hi) / 2;
        long cnt = 0;
        for(long i: a){
            if(i > mid) cnt += i-mid;
        }
        if(cnt < m) hi = mid-1;
        else {
            lo = mid+1;
            if(ans < mid) ans = mid;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i < n; i++){
        long input;
        cin >> input;
        a.push_back(input);
        if(hi < input) hi = input;
    }
    bis();
    cout << ans;
}