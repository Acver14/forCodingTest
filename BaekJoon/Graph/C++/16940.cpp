//2021.09.07
//2021.09.08 (study)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v[100001];
vector<int> comp;
bool check[100001];
int n;

void bfs(int start){
    check[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        comp.push_back(node);
        for(int i: v[node]){
            if(check[i] == false){
                q.push(i);
                check[i] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    vector<int> ans(n+1, 0);
    vector<int> idx(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int to, from;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> ans[i];
        idx[ans[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end(), [&](const int& u, const int& v)
            {
                return idx[u] < idx[v];
            });
    }

    comp.push_back(0);
    if(ans[1] != 1){
        cout << 0 << '\n';
        return 0;
    }
    bfs(ans[1]);
    if(ans == comp) cout << 1 << '\n';
    else cout << 0 << '\n';
    
    return 0;
}