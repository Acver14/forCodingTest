//2021.09.15
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n;
vector<int> tree[100001];
vector<int> parent;
void findParent(){
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i: tree[node]){
            if(parent[i] == 0){
                parent[i] = node;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    parent.resize(n+1);

    for(int i = 1; i < n; i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    findParent();

    for(int i = 2; i <= n; i++){
        cout << parent[i] << '\n';
    }

}