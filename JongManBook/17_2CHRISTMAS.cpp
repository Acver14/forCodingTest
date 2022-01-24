//2022.01.24
#include<iostream>
using namespace std;

int k;
int n;
int d[100000];
int sum[100000];
int dp[100000];

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

long long orderGiftOne(){
    long long ans = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            if(j == i){
                if(sum[i] % k == 0) ans++;
            }else{
                if((sum[i] - sum[j]) % k == 0) ans++;
            }
            ans %= 20091101;
        }
    }
    return ans;
}

int orderGifts(){
    if(sum[0] % k == 0) dp[0] = 1;
    else dp[0] = 0;
    
    int ret = dp[0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if((sum[i] - sum[j]) % k == 0){
                dp[i] = dp[j]+1;
                ret = findMax(dp[i], ret);
            }
        }
    }
    return ret;
}


void init(){
    for(int i = 0; i < 100000; i++){
        d[i] = sum[i] = 0;
        dp[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        init();
        cin >> n >> k;
        for(int  j = 0; j < n; j++){
            cin >> d[j];
            sum[j] = (j!=0?sum[j-1]:0) + d[j];
        }

        cout << orderGiftOne() << ' ' << orderGifts() << '\n';
    }

}