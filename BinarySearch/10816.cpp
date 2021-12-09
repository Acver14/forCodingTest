//2021.12.09
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<long long> a;
vector<long long> b;
int lo, hi;

int lowerBound(long long target){
    lo = 0;
    hi = n;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(a[mid] < target) lo = mid+1;
        else if(a[mid] >= target) hi = mid;
    }
    return lo;
}

int upperBound(long long target){
    lo = 0;
    hi = n;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(a[mid] <= target) lo = mid+1;
        else if(a[mid] > target) hi = mid;
    }
    return lo;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        long long input;
        cin >> input;
        a.push_back(input);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        long long input;
        cin >> input;
        b.push_back(input);
    }
    
    sort(a.begin(), a.end());
    cout << '\n';
    for(long long i: b){
        cout << upperBound(i) - lowerBound(i) << ' ';
    }
}