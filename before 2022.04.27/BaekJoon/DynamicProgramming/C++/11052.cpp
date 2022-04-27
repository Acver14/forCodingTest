//2021.08.04
#include<iostream>

using namespace std;

int findMax(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int P[10001] = {0, };
    int D[10001] = {0, };
    int n = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> P[i];
    }

    D[1] = P[1];
 
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= i; j++){
            D[i] = findMax(D[i], D[i-j] + P[j]);
        }
    }

    cout << D[n];
}