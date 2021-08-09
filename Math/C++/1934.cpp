//2021.08.02
#include<iostream>
using namespace std;

int getGcd(int a, int b);
int getLcm(int a, int b);

int main(){
    int a, b;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;

        cout << getLcm(a, b) << '\n';
    }
}


int getGcd(int a, int b){
    if(b == 0) return a;
    else return getGcd(b, a%b);
}
int getLcm(int a, int b){
    int gcd = getGcd(a, b);
    return gcd * (a/gcd) * (b/gcd);
}