//2021.10.12
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

class point{
public:
    int x, y, dist, broken;
    point(int X, int Y, int D, int B){
        x = X; y = Y; dist = D; broken = B;
    }
};

int a[1000][1000];
bool check[1000][1000][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;

bool isIn(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

int bfs(){
    queue<point> q;
    q.push(point(0, 0, 1, 0));
    while (!q.empty()){
        point node = q.front(); q.pop();
        if(node.x == n-1 && node.y == m-1){
            return node.dist;
        }
        for(int i = 0; i < 4; i++){
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(isIn(nx, ny) && check[nx][ny][node.broken] == false){
                if(a[nx][ny] == 0){
                    check[nx][ny][node.broken] = true;
                    q.push(point(nx, ny, node.dist+1, node.broken));
                }
                else if(a[nx][ny] == 1 && node.broken < k){
                    check[nx][ny][node.broken] = true;
                    q.push(point(nx, ny, node.dist+1, node.broken+1));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++){
            a[i][j] = s[j] - '0';
        }
    }

    int result = bfs();
    cout << result;
}