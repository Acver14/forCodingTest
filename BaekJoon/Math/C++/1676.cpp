//2021.08.03
#include<iostream>

using namespace std;

int countZeroOfFac(int n);

int main(){
    int n;
    cin >> n;
    cout << countZeroOfFac(n);
}

int countZeroOfFac(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int tmp = i;
        while(tmp % 5 == 0){
            cnt++;
            tmp /= 5;
        }
    }

    return cnt;
}