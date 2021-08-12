//2021.08.06
//retry at 2021.08.12

#include<iostream>
#include<vector>
using namespace std;

vector<int> pos;
vector<int> A;

int findMax(int a, int b){
    if(a > b) return a;
    return b;
}

void go(int p){
    if(p == -1) return;
    go(pos[p]);
    cout << A[p] << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> D(n);

    A.resize(n);
    pos.resize(n);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        D[i] = 1;
        pos[i] = -1;
        for(int j = 0; j < i; j++){
            if(A[j] < A[i] && D[i] < D[j] + 1){
                D[i] = D[j] + 1;
                pos[i] = j;
            }
        }
    }
    int max = D[0];
    int p = 0;
    for(int i = 1; i < n; i++){
        if(max < D[i]){
            max = D[i];
            p = i;
        }
    
    }
    cout << max << '\n';
    go(p);
}