//2021.09.17
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int num[20];
bool check[20];
bool ansCheck[20*100000];

void go(int idx, int result){
    if (idx == n) {
        ansCheck[result] = true;
        return;
    }
    go(idx+1, result+num[idx]);
    go(idx+1, result);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    
    go(0, 0);
    int x = 1;
    while(true){
        if(ansCheck[x] == false) {
            cout << x;
            return 0;
        }   
        x++;
    }
}