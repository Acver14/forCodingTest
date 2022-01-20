//2021.09.01
#include<iostream>
#include<vector>
using namespace std;

short color[20001];
vector<int> v[20001];
int n, m;

bool dfs(int x, int c){
    color[x] = c;
    int size = v[x].size();
    for(int i = 0; i < size; i++){
        int next = v[x][i];
        if(color[next] == 0){
            if(dfs(next, 3-c) == false) return false;
        }
        else if(color[x] == color[next]) return false;
    }
    return true;
}

int main(){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            color[i] = 0;
            v[i].clear();
        }
        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                if(dfs(i, 1) == false) ok = false;
            }
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    
}