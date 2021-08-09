//2021.07.25
#include<iostream>
using namespace std;

int p[10001] = {0, };
int D[10001] = {0, };
int findMaxOfThree(int a, int b, int c);
int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    D[1] = p[1];
    D[2] = p[2] + D[1];

    for(int i = 3; i <= n; i++){
        D[i] = findMaxOfThree(D[i-1], D[i-2]+p[i], D[i-3]+p[i-1]+p[i]);
    }
    cout << D[n];

    return 0;
}

int findMaxOfThree(int a, int b, int c){
    int ret = a;
    if(ret < b) ret = b;
    if(ret < c) ret = c;
    return ret;
}