//2021.10.05
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];
int n;

bool isIn(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    return true;
}

void bfs(int sx, int sy){
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    dist[sx][sy] = 0;
    while(!q.empty()){
        pair<int, int> node = q.front(); q.pop();
        for(int i = 0; i < 6; i++){
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            if(isIn(nx, ny)){
                if(dist[nx][ny] == -1){
                    dist[nx][ny] = dist[node.first][node.second]+1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    int sx, sy, dx, dy;
    cin >> n >> sx >> sy >> dx >> dy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = -1;
        }
    }
    bfs(sx, sy);
    cout << dist[dx][dy];
    return 0;
}