//2021.08.03
#include<iostream>
#include<vector>

using namespace std;

int getGCD(int a, int b);

int main(){
    int n, s;
    vector<int> a;

    cin >> n >> s;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for(int i = 0; i < n; i++){
        if(a[i] > s) a[i] = a[i] - s;
        else a[i] = s - a[i];
    }

    long long ans = a[0];
    for(int i = 0; i < n-1; i++){
        ans = getGCD(ans, a[i+1]);
    }
    cout << ans;
}

int getGCD(int a, int b){
    if(b == 0) return a;
    else return getGCD(b, a%b);
}