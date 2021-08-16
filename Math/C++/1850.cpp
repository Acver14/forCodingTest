//2021.08.13
#include<iostream>

using namespace std;

long long GCD(long long a, long long b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}

int main(){
    long long a, b;

    cin >> a >> b;
    int gcd = GCD(a, b);

    for(int i = 0; i < gcd; i++) cout << 1;
}