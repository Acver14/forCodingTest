//2021.12.16
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> p;
vector<int> m;
vector<int> remain;

bool comp(int x, int y){
    if(x > y) return true;
    return false;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

long long greedy(vector<int> a){
    long long sum = 0;
    while(a.size() > 1){
        int i = a.size()-1;
        if(a[i]+a[i-1] >= a[i]*a[i-1]){
            sum += a[i];
        }
        else{
            sum += a[i]*a[i-1];
            a.pop_back();
        }
        a.pop_back();
    }
    if(a.size() == 1) remain.push_back(a[0]);
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(input > 0) p.push_back(input);
        else m.push_back(input);
    }

    sort(m.begin(), m.end(), comp);
    sort(p.begin(), p.end());
    long long ans = greedy(p) + greedy(m);
    if(remain.size() == 2) ans += max(remain[0]+remain[1], remain[0]*remain[1]);
    if(remain.size() == 1) ans += remain[0];
    cout << ans;

}