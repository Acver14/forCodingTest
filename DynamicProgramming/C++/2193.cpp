//2021.07.20
#include<iostream>
using namespace std;

long long D[91][2] = {{0, }};

int main(){
    int n = 0;
    cin >> n;

    D[1][0] = 0;
    D[1][1] = 1;
    D[2][0] = 1;
    D[2][1] = 0;
    for(int i = 3; i <= n; i++){
        D[i][0] = D[i-1][0] + D[i-1][1];
        D[i][1] = D[i-1][0];
    }
    
    cout << D[n][0] + D[n][1];
    return 0;
}

// #include<iostream>
// using namespace std;

// long long D[91]={0,};

// int main(){
//     int n = 0;
//     cin >> n;

//     D[1] = 1;
//     D[2] = 1;
//     D[3] = 2;

//     for(int i = 4; i <= n; i++){
//         D[i] = D[i-1] + D[i-2];
//     }

//     cout << D[n];
//     return 0;
// }