//2021.07.21
#include<iostream>
using namespace std;

int main(){
    int n;
    int max, min;
    int input;

    cin >> n;
    cin >> input;
    max = min = input;
    for(int i = 1; i < n; i++){
        cin >> input;
        if(max < input) max = input;
        if(min > input) min = input;
    }
    cout << min << " " << max;

    return 0;
}