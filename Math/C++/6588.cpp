//2021.08.03
#include<iostream>
using namespace std;

bool check[1000001];
int prime[1000000];
int pn = 0;

void checkPrime(){
    check[0] = check[1] = true;
    for(int i = 2; i <= 1000001; i++){
        if(check[i] == false) {
            prime[pn++] = i;
            for(int j = i*2; j <=1000001; j+=i){
                check[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    checkPrime();
    int x;
    while(true){
        cin >> x;
        if(x == 0) break;
        for(int j = 1; j < pn; j++){
            if(!check[x-prime[j]]){
                cout << x << " = " << prime[j] << " + " << x - prime[j] << '\n';
                break;
            }
            if(j == x-1) cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
}