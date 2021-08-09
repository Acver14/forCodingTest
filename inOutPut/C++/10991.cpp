//2021.07.23
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = n-1; i > -1; i--){
        for(int j = 0; j < n; j++){
            if(i-1 < j) cout <<'*';
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}