//2021.12.08
#include<iostream>
#include<vector>
using namespace std;

long n, k;
long lo = 1;
long hi;
long ans = 0;
vector<long> lan;

void bis(){
    while(lo <= hi){
        long mid = (lo + hi) / 2;
        long cnt = 0;
        for(int i: lan){
            cnt += i/mid;
        }
        if(cnt < n) hi = mid-1;
        else {
            lo = mid+1;
            if(ans < mid) ans = mid;
        }
    }
}

int main(){
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        long input;
        cin >> input;
        lan.push_back(input);
        if(hi < input) hi = input;
    }
    bis();
    cout << ans;
}