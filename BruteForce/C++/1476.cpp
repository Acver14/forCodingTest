//2021.08.16
#include<iostream>
using namespace std;

int main(){
    int e, s, m, E, S, M;
    cin >> e >> s >> m;
    E=S=M=1;
    int year = 1;
    while(true){
        if(e==E && s==S && m==M){
            cout << year;
            return 0;
        }else{
            E++;
            S++;
            M++;
            year++;
            if(E == 16) E = 1;
            if(S == 29) S = 1;
            if(M == 20) M = 1;
        }
    }
}