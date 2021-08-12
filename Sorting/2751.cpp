//2021.08.12
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    
    for(const auto &item: A){
        cout << item << '\n';
    }
}