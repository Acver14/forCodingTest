//2021.08.03
#include<iostream>
using namespace std;

int getGCD(int a, int b);

int main(){
    int t;
    int num[101] = {0, };
    cin >> t;

    long long ans = 0;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> num[j];
        }
        for(int j = 0; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                ans += getGCD(num[j], num[k]);
            }
        }
        cout <<  ans << '\n';
        ans = 0;
    }
}

int getGCD(int a, int b){
    if(b == 0) return a;
    else return getGCD(b, a%b);
}