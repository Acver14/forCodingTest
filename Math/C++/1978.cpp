//2021.08.02
#include<iostream>
using namespace std;

bool isPrime(int a);

int main(){
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(isPrime(x)) cnt++;
    }
    cout << cnt;
}

bool isPrime(int a){
    if(a < 2) return false;
    for(int i = 2; i*2 <= a; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}