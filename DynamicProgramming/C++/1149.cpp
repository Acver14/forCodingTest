//2021.08.09
#include<iostream>
using namespace std;

int findMin(int a, int b){
    if(a < b) return a;
    return b;
}

int main(){
    int n;
    int A[1000][3];
    int D[1000][3];
    cin >> n;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> A[i][j];
        }
    }

    D[0][0] = A[0][0];
    D[0][1] = A[0][1];
    D[0][2] = A[0][2];

    for(int i = 1; i < n; i++){
        D[i][0] = findMin(D[i-1][1] + A[i][0], D[i-1][2] + A[i][0]);
        D[i][1] = findMin(D[i-1][0] + A[i][1], D[i-1][2] + A[i][1]);
        D[i][2] = findMin(D[i-1][1] + A[i][2], D[i-1][0] + A[i][2]);
    }

    cout << findMin(findMin(D[n-1][0], D[n-1][1]), D[n-1][2]);
}