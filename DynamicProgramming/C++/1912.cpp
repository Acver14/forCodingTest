//2021.08.08
#include<iostream>
#include<vector>
using namespace std;

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    int A[100001];
    int D[100001];


    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int ans = A[0];

    for(int i = 0; i < n; i++){
        if(D[i-1] < 0) D[i] = A[i];
        else D[i] = D[i-1] + A[i];
        ans = findMax(D[i], ans);
    }

    cout << ans;
}