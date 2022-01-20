//2021.08.03
#include<iostream>
using namespace std;

int getFac(int n);
int main(){
    int n;
    cin >> n;
    cout << getFac(n);
}

int getFac(int n){
    if(n > 1) return n * getFac(n-1);
    else return 1;
}