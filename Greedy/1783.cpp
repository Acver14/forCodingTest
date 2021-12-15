//2021.12.15
#include<iostream>
using namespace std;

int min(int a, int b){
    return a < b? a:b;
}

int main(){
    long long n, m;
    cin >> n >> m;

    if(n==1) cout << 1;
    else if(n == 2) cout << min(4, (m+1)/2);
    else if(m < 7) cout << min(4, m);
    else cout << m - 7 + 5;
    return 0;
}