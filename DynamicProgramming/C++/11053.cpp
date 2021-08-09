//2021.07.26
#include<iostream>
using namespace std;

int A[1001] = {0, };
int D[1001] = {0, };

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    int n;
    cin >> n;
    int cnt = 1;

    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    fill_n(D, n+1, 1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(A[i] > A[j]){
                D[i] = findMax(D[i], D[j] + 1);
            }
        }
        cnt = findMax(D[i], cnt);
    }

    cout << cnt;
}