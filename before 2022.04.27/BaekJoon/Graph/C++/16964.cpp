//2021.09.08
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check[100001];
vector<int> v[100001];
vector<int> comp;

void dfs(int x) {
    if (check[x] == true) {
        return;
    }
    check[x] = true;
    int node = x;
    comp.push_back(x);
    for (int y : v[node]) {
        if (check[y] == false) {
            dfs(y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ans(n+1);
    vector<int> idx(n+1);
    for(int i = 0; i < n-1; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for(int i = 1; i <= n; i++){
        cin >> ans[i];
        idx[ans[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end(), [&](const int& u, const int& v){
            return idx[u] < idx[v];
        });
    }

    comp.push_back(0);
    if(ans[1] == 1){
        dfs(1);
        if(ans == comp){
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}
