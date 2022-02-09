//2022.02.09
#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int top = q.front();
    while(q.size() > 1){
        q.pop();
        top = q.front();
        q.pop();
        q.push(top);
    }

    cout << top;
}