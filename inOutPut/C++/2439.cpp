//2021.07.22
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = n-1; i > -1; i--){
        for(int j = 0; j < n; j++){
            if(j < i) cout << " ";
            else cout << "*";
        }
        cout << '\n';
    }

    return 0;
}