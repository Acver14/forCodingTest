//2021.08.12
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int A[1000];
    int D[1000];
    int n, ans;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[j] > A[i] && D[i] < D[j]+1){
                D[i] = D[j] + 1;
            }
        }
    }
    ans = D[0];
    for(int i = 1; i < n; i++){
        if(ans < D[i]) ans = D[i];
    }
    cout << ans;
}