//2021.07.21
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << i << '\n';          // endl 은 flush()를 겸하기 때문에 \n 보다 속도가 느리다.
    }
}