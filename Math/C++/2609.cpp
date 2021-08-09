//2021.08.02
#include<iostream>
using namespace std;

int getGcd(int a, int b);
int getLcm(int a, int b);

int main(){
    int a, b;
    
    cin >> a >> b;

    cout << getGcd(a, b) << '\n';
    cout << getLcm(a, b);
}


int getGcd(int a, int b){
    if(b == 0) return a;
    else return getGcd(b, a%b);
}
int getLcm(int a, int b){
    int gcd = getGcd(a, b);
    return gcd * (a/gcd) * (b/gcd);
}