//2021.08.19
#include<iostream>
using namespace std;

int a[10];

void printNum(int index, int n, int m){
    if(index == m){
        for(int i = 0; i < m; i++){
            cout << a[i];
            if(i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        a[index] = i;
        printNum(index+1, n, m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    printNum(0, n, m);
}