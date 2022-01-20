//2021.08.22
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int W[11][11];


int main(){
    int n;
    cin >> n;
    vector<int> p(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> W[i][j];
        }
        p[i] = i;
    }
    int sum = 0;
    int ans = 1000000*5;
    do{
        for(int i = 1; i < n; i++){
            if(W[p[i-1]][p[i]] != 0){
                sum += W[p[i-1]][p[i]];
            }
            else {
                sum = 1000000*5;
                break;
            }
        }
        if(W[p[n-1]][p[0]] != 0){
            sum += W[p[n-1]][p[0]];
            if(ans > sum) ans = sum;
        }
        sum = 0;
    }while(next_permutation(p.begin() + 1, p.end()));
    cout << ans;
}