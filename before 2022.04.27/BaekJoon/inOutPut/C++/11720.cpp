//2021.07.20
#include<iostream>
using namespace std;

int main(){
    char c;
    int n;
    int sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        sum += c - '0';
    }
    cout << sum;

    return 0;
}