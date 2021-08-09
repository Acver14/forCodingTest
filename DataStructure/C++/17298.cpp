//2021.07.29
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int A[1000001] = { -1, };
    int result[1000001];
    stack<int> s;

    
    cin >> n;
    fill_n(result, n+1, -1);
    
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    s.push(0);
    for(int i = 1; i <= n; i++){
        while(!s.empty() && A[i] > A[s.top()]){
            result[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    result[n] = -1;

    for(int i = 1; i <= n; i++){
        cout << result[i] << ' ';
    }

    return 0;
}