//2021.08.06
#include<iostream>
#include<vector>
using namespace std;

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    int A[1001] = {0, };
    int D[1001];
    int n;
    vector<int> ans;

    int len = 1;
    fill_n(D, n, 1);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                D[i] = findMax(D[i], D[j]+1);
            }
        }
    }
}