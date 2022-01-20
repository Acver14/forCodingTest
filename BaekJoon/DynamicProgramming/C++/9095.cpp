//2021.07.15
#include<iostream>
using namespace std;

int D[12];
int main(){
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    int t;
    int n;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 4; j <= n; j++){
            D[j] = D[j-1] + D[j-2] + D[j-3];
        }
        cout << D[n] << "\n";
    }

    return 0;
}