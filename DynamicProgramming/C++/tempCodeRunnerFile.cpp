//2021.08.08
#include<iostream>
#include<vector>
using namespace std;

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    int A[100001];
    vector<int> D;


    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
        D.push_back(0);
    }
    int ans = A[0];

    for(int i = 0; i < n; i++){
        int temp = D[i] = A[i];
        for(int j = i; j > -1; j--){
            D[i] += A[j];
            temp = findMax(D[i], ans);
            ans = findMax(temp, ans);
        }
    }

    cout << ans;
}