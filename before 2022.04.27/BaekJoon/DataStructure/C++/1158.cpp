//2021.07.28
#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    queue<int> q;
    queue<int> ans;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i = 0; i < m-1; i++){
            q.push(q.front());
            q.pop();
        }
        ans.push(q.front());
        q.pop();
    }

    cout << "<";
    while(!ans.empty()){
        cout << ans.front();
        ans.pop();
        if(!ans.empty()) cout << ", ";
    }
    cout << ">";
}