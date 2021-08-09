//2021.08.06
#include<iostream>
using namespace std;

int findMin(int a, int b){
    if (a < b) return a;
    else return b;
    
}

int main(){
    int P[10001] = {0, };
    int D[10001] = {0, };
    int n;
    
    fill_n(D, 10001, 10001);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> P[i];
    }

    D[1] = P[1];
    D[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            D[i] = findMin(D[i], D[i-j] + P[j]);
        }
    }

    cout << D[n];
}