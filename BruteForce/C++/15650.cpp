//2021.08.19
#include<iostream>
using namespace std;

bool c[10];
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
    for(int i = a[index-1]+1; i <= n; i++){
        if(c[i]) continue;
        c[i] = true;
        a[index] = i;
        printNum(index+1, n, m);
        c[i] = false;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    printNum(0, n, m);
}