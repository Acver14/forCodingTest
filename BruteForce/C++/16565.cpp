//2021.08.19
#include<iostream>
#include<algorithm>
using namespace std;

bool c[10];
int a[10];
int num[10];

void printNum(int index, int start, int n, int m){
    if(index == m){
        for(int i = 0; i < m; i++){
            cout << num[a[i]];
            if(i != m) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i < n; i++){
        if(c[i]) continue;
        c[i] = true;
        a[index] = i;
        printNum(index+1, a[index]+1, n, m);
        c[i] = false;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num+n);
    printNum(0, 0, n, m);
}