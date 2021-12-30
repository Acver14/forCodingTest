//2021.12.30
#include<iostream>
#include<queue>
using namespace std;

int n, m, k;
char a[100][100];
int dp[100][100][80];
string comp = "";
int ans = 0;

struct pos{
    int x, y;
    int idx;
}typedef pos;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(pos p){
    if(dp[p.x][p.y][p.idx] != -1) return dp[p.x][p.y][p.idx];
    if(a[p.x][p.y] != comp[p.idx]) return 0;
    if(p.idx+1 == comp.length()) {
        return 1;
    }
    dp[p.x][p.y][p.idx] = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= k; j++){
            int nx = p.x + dx[i] * j;
            int ny = p.y + dy[i] * j;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            dp[p.x][p.y][p.idx] += dfs({nx, ny, p.idx+1});
        }
    }
    return dp[p.x][p.y][p.idx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    cin >> comp;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) for(int t = 0; t < 80; t++) dp[i][j][t] = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += dfs({i, j, 0});
        }
    }

    cout << ans;
}