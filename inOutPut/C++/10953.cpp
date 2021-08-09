//2017.07.16
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    int a, b;
    char del;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> del >> b;
        cout << a + b << '\n';
        
    }
    return 0;
}