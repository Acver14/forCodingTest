//2021.08.20
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findDiff(vector<int> a, int len){
    int diff = 0;
    for(int i = 0; i < len-1; i++){
        diff += abs(a[i] - a[i+1]);
    }
    return diff;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = findDiff(a, n);
    while(next_permutation(a.begin(), a.end())){
        int diff = findDiff(a, n);
        if(ans < diff) ans = diff;
    }
    cout << ans;
}