//2021.08.20
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool next_p(int *a, int n){
    int index = n-1;
    int min;
    int i = n-1;
    for(; i > 0; i--){
        if(a[i-1] < a[i]) {
            break;
        }
    }
    min = a[i];
    for(int j = i; j < n; j++){
        if(min > a[j] && a[j] > a[i-1]){
            index = j;
            min = a[j];
        }
    }
    if(i != 0){
        swap(a[i-1], a[index]);
        sort(a+i, a+n);
        return true;
    }
    else return false;
    
}

int main(){
    int n;
    cin >> n;

    vector<int> b(n);
    int a[10001];

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = b[i] = temp;
        
    }

    if(next_permutation(b.begin(), b.end())){
        for(int i = 0 ; i < n; i++){
            cout << b[i] << ' ';
        }
    }
    else cout << -1;
    cout << '\n';
    if(next_p(a, n)){
        for(int i = 0 ; i < n; i++){
            cout << a[i] << ' ';
        }
    }
    else cout << -1;
}