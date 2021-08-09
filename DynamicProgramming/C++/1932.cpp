#include<iostream>
#include<vector>

using namespace std;

int findMax(int a, int b){
    if(a < b) return b;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    int D[500][500];
    int max = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> D[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) D[i][j] = D[i-1][0] + D[i][j];
            else if(j == i) D[i][j] = D[i-1][j-1] + D[i][j];
            else D[i][j] = findMax(D[i-1][j-1] + D[i][j], D[i-1][j] + D[i][j]);
            max = findMax(D[i][j], max);
        }
    }
    cout << max;
}