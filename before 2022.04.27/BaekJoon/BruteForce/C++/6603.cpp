//2021.08.22
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int k[13];
    int cnt = 6;
    while(true){
        cin >> n;
        vector<int> ind(n);
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> k[i];
            if(i < 6)ind[i] = 0;
            else ind[i] = 1;
        }
        sort(ind.begin(), ind.end());
        do{
            for(int i = 0; i < n; i++){
                if(ind[i]==0){
                    cout << k[i] << ' ';
                }
            }
            cout << '\n';
        }while(next_permutation(ind.begin(), ind.end()));
        cout << '\n';
    }
}