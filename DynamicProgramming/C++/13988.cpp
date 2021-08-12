//2021.08.12
#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> DL(n);
    vector<int> DR(n);
    int max;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    DL[0] = A[0];
    for(int i = 1; i < n; i++){
        DL[i] = A[i];
        if(DL[i] < DL[i-1] + A[i]) DL[i] = DL[i-1] + A[i];
    }
    DR[n-1] = A[n-1];
    for(int i = n-2; i > -1; i--){
        DR[i] = A[i];
        if(DR[i] < DR[i+1] + A[i]) DR[i] = DR[i+1] + A[i];
    }

    max = DL[0];
    for(int i = 1; i < n; i++){
        if(max < DL[i]) max = DL[i];
    }

    for(int i = 1; i < n-1; i++){
        if(max < DL[i-1] + DR[i+1]) {
            max = DL[i-1] + DR[i+1];
        }
    }

    cout << max;
}