//2021.08.12
#include<iostream>
using namespace std;

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int A[1001];
    int D[1001];
    int n, max = 0;

    cin >> n; 

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        D[i] = A[i];
        for(int j = 0; j < i; j++){
            if(A[j] < A[i] && D[i] < D[j] + A[i]){
                D[i] = D[j] + A[i];
                // max = findMax(max, D[i]);
            }
        }
    }
    max = D[0];
    for(int i = 1; i < n; i++){
        max = findMax(max, D[i]);
    }
    cout << max << '\n';
}

// 코드상 max 값을 추출하는데 차이가 뭔지 생각해보기.