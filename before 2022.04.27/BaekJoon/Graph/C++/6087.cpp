//2021.12.02
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct pos{
    int x, y, dir, val;
}typedef pos;

int w, h;
char a[101][101];
int change[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pos> v;

bool isPossible(pos p){
    if(p.x < 0 || p. y < 0 || p.x >= h || p.y >= w) return false;
    return true;
}

void bfs(){
    queue<pos> q;
    q.push(v[0]);
    while(!q.empty()){
        pos node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pos next = {node.x+dx[i], node.y+dy[i], i, node.val};
            if(isPossible(next) && !(next.x==v[0].x && next.y==v[0].y)){
                if(a[next.x][next.y] != '*'){
                    if(node.dir != next.dir) next.val += 1;

                    if(change[next.x][next.y] >= next.val || change[next.x][next.y] == -1){
                        change[next.x][next.y] = next.val;
                        q.push(next);
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            change[i][j] = -1;
            cin >> a[i][j];
            if(a[i][j] == 'C') {v.push_back({i,j, -1, -1});}
        }
    }
    bfs();
    cout << change[v[1].x][v[1].y];
}