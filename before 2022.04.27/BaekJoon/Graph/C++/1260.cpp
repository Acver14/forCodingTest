//2021.08.31
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> vertex[1001];
bool check[1001] = {false, };
int n, m, v;

queue<int> q;

void dfs(int x){
    check[x] = true;
    cout << x << ' ';
    int size = vertex[x].size();
    for(int i = 0; i < size; i++){
        if(!check[vertex[x][i]]){
            dfs(vertex[x][i]);
        }
    }
}

void bfs(int x){
    q.push(x);
    check[x] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << ' ';
        int size = vertex[node].size();
        for(int i = 0; i < size; i++){
            int next = vertex[node][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        vertex[from].push_back(to);
        vertex[to].push_back(from);
    }
    for(int i = 1; i <= n; i++){
        sort(vertex[i].begin(), vertex[i].end());
    }
    dfs(v);
    fill_n(check, 1001, false);
    cout << '\n';
    bfs(v);
}