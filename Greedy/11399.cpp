//2021.12.16
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        p.push_back(input);
    }

    sort(p.begin(), p.end());

    int waitT = 0;
    int ans = 0;
    for(int i: p){
        waitT = i+waitT;
        ans += waitT;
    }

    cout << ans;
}