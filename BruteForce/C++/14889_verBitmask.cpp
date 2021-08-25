//2021.08.25
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int S[20][20];
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> S[i][j];
        }
    }
    int ans = -1;
    for(int i = 0; i < (1<<n); i++){
        vector<int> first, second;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)) first.push_back(j);
            else second.push_back(j);
        }
        if(first.size() != n/2) continue;
        int t1 = 0;
        int t2 = 0;
        for(int a = 0; a < n/2; a++){
            for(int b = 0; b < n/2; b++){
                if(a == b) continue;
                t1 += S[first[a]][first[b]];
                t2 += S[second[a]][second[b]];
            }
        }
        int diff = t1 - t2;
        if(diff < 0) diff = -diff;
        if(ans == -1 || ans > diff) ans = diff;
    }
    cout << ans;
}