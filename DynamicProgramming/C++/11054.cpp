//2021.08.12
#include<iostream>
using namespace std;

int main(){
    int A[1000];
    int DL[1000];
    int DR[1000];
    int n;
    int max;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    fill_n(DR, n, 1);
    for(int i = 0; i < n; i++){
        DL[i] = 1;
        for(int j = 0; j <= i; j++){
            if(A[j] < A[i] && DL[i] < DL[j]+1){
                DL[i] = DL[j] + 1;
            }
        }
    }
    for(int i = n-1; i > -1; i--){
        DR[i] = 1;
        for(int j = n-1; j >= i; j--){
            if(A[j] < A[i] && DR[i] < DR[j]+1){
                DR[i] = DR[j] + 1;
            }
        }
    }
    max = DL[0] + DR[0] - 1;
    for(int i = 0; i < n; i++){
        if(max < DL[i] + DR[i] - 1){
            max = DL[i] + DR[i] - 1;
        }
    }

    cout << max;
}