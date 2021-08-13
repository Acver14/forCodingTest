//2021.08.13
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int A[10001] = {0,};
    int max = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(max < a) max = a;
        A[a]++;
    }

    for(int i = 1; i <= max; i++){
        for(int j = 0; j < A[i]; j++){
            cout << i << '\n';
        }
    }
}