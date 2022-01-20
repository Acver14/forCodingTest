//2021.09.01
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check[1001];
vector<int> v[1001];
int n, m;

void dfs(int x){
    check[x] = true;
    int size = v[x].size();
    for(int i = 0; i < size; i++){
        if(!check[v[x][i]]){
            dfs(v[x][i]);
        }
    }
}

int main(){
    int component = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());

    }
    for(int i = 1; i <= n; i++){
        if(check[i]) continue;
        else{
            dfs(i);
            component++;
        }
    }

    cout << component;
}