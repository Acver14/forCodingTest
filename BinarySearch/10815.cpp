//2021.12.08
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> a;
vector<int> comp;

bool bis(int target){
    int hi, lo;
    hi = n-1;
    lo = 0;
    while(lo <= hi){
        int mid = (lo+hi) / 2;
        if(target == a[mid]) return true;
        if(target < a[mid]) hi = mid-1;
        else lo = mid+1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    cin >> m;
    for(int i = 0; i < m; i++){
        int input;
        cin >> input;
        comp.push_back(input);
    }

    for(int i = 0; i < m; i++){
        if(bis(comp[i]))cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}