//2021.08.08
#include<iostream>
using namespace std;

int findMin(int a, int b){
    if(a < b) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    int D[100000] = {0, };
    cin >> n;

    for(int i = 1; i <= n; i++){
        D[i] = i;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j * j <= i; j++){
            D[i] = findMin(D[i], D[i - j*j] + 1);
        }
    }
    cout << D[n];
}