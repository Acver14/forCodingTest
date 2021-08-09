//2021.07.21 fail
//2021.07.23 retry
#include <iostream>
using namespace std;

int D[2][100003] = {{0,}};
int findMax(int a, int b);
int main(){
    int t, n;
    cin >> t;

    for(int testCase = 0; testCase < t; testCase++){
        cin >> n;
        for(int i = 0; i < 2; i++){
            for(int j = 3; j < n+3; j++){
                cin >> D[i][j];
            }
        }

        for(int i = 3; i < n+2; i++){
            D[0][i] += findMax(D[1][i-1], D[1][i-2]);
            D[1][i] += findMax(D[0][i-1], D[0][i-2]);
        }

        int ans = findMax(D[0][n+2], D[1][n+2]);

        cout << ans << '\n';
    }
    return 0;
}

int findMax(int a, int b){
    if(a > b) return a;
    else return b;
}