//2021.12.06
#include<iostream>
#include<queue>
using namespace std;

int n;
char a[100][100];
bool check[100][100][2];
int ans = 0;
int wAns = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct pos{
    int x, y;
};

bool isPossible(pos p){
    if(p.x < 0 || p.y < 0 || p.x >= n || p.y >= n) return false;
    return true;
}

bool bfs(int x, int y){
    if(check[x][y][0]) return false;
    queue<pos> q;
    q.push({x, y});
    char color = a[x][y];
    while(!q.empty()){
        pos node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pos next = {node.x+dx[i], node.y+dy[i]};
            if(isPossible(next) && check[next.x][next.y][0] == false){
                if(a[next.x][next.y] == color){
                    check[next.x][next.y][0] = true;
                    q.push(next);
                }
            }
        }
    }
    return true;
}

bool wbfs(int x, int y){
    if(check[x][y][1]) return false;
    queue<pos> q;
    q.push({x, y});
    char color = a[x][y];
    while(!q.empty()){
        pos node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pos next = {node.x+dx[i], node.y+dy[i]};
            if(isPossible(next) && check[next.x][next.y][1] == false){
                if(color == 'R' || color == 'G'){
                    if(a[next.x][next.y] == 'R' || a[next.x][next.y] == 'G'){
                        check[next.x][next.y][1] = true;
                        q.push(next);
                    }
                }else{
                    if(a[next.x][next.y] == 'B'){
                        check[next.x][next.y][1] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool existArea = bfs(i, j);
            bool wExistArea = wbfs(i, j);
            if(existArea) ans++;
            if(wExistArea) wAns++;
        }
    }

    cout << ans << ' '<< wAns << '\n';
}