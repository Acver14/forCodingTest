//2021.10.07
#include<iostream>
#include<queue>
using namespace std;

class point{
public:
    int x, y, dist;
    bool broken;
    point(){
        x = y = broken = 0;
        dist = 1;
    }
    point(int X, int Y, int D, bool B){
        x = X;
        y = Y;
        dist = D;
        broken = B;
    }
};

int n, m;
int a[1001][1001];
bool check[1001][1001][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isIn(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

void bfs(){
    queue<point> q;
    q.push(point(1, 1, 1, 0));
    while(!q.empty()){
        point node = q.front(); q.pop();
        if(node.x == n && node.y == m) {
            cout << node.dist;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = node.x+dx[i];
            int ny = node.y+dy[i];
            if(isIn(nx, ny) && check[nx][ny][node.broken] == false){
                if(a[nx][ny] == 0){
                    q.push(point(nx, ny, node.dist+1, node.broken));
                    check[nx][ny][node.broken] = true;
                }else{
                    if(node.broken == false){
                        q.push(point(nx, ny, node.dist+1, true));
                        check[nx][ny][node.broken] = true;
                    }
                }
            }
        }   
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            a[i][j+1] = input[j]-'0';
        }
    }
    bfs();
}