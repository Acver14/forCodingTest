//2021.08.01
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int fA[1000001] = {0,};

    cin >> n;
    
    vector<int> A(n);
    vector<int> ans(n);
    stack<int> s;

    for(int i = 0; i < n; i++){
        cin >> A[i];
        fA[A[i]] += 1;
    }
    s.push(0);
    
    for(int i = 1; i <= n; i++){
        while(!s.empty() && fA[A[s.top()]] < fA[A[i]]){{
            ans[s.top()] = A[i];
            s.pop();
        }}
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = -1;
        s.pop();
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}