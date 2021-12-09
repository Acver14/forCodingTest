//2021.12.09
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, c;
int lo = 1;
int hi = 0;
int ans = 0;
vector<int> x;

void bis(){
    int d = 0;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        int cnt = 1;
        int start = x[0];

        for(int i = 1; i < n; i++){
            d = x[i] - start;
            if(mid <= d){
                cnt+=1;
                start = x[i];
            }
        }

        if(cnt >= c){
            ans = mid;
            lo = mid+1;
        }else hi = mid-1;
    }
}

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        x.push_back(input);
    }

    sort(x.begin(), x.end());
    lo = 1;
    hi = x.back() - x.front();
    bis();
    cout << ans << '\n';
}