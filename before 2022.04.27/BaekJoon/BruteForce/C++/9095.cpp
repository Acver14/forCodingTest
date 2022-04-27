//2021.08.22
#include<iostream>
using namespace std;
int solve(int n, int sum, int cnt);

int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int ans;
        ans = solve(n, 0, 0);
        cout << ans << '\n';
    }
}
int solve(int n, int sum, int cnt){
    if(n < sum) return 0;
    if(n == sum) return 1;
    else{
        if(n == sum+1){
            return solve(n, sum+1, cnt+1);
        }else if(n == sum + 2){
            return solve(n, sum+1, cnt+1) + solve(n, sum+2, cnt+1);
        }
        else {
            return solve(n, sum+1, cnt+1) + solve(n, sum+2, cnt+1) + solve(n, sum+3, cnt+1);
            }
    }
}