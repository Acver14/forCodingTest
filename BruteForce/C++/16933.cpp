//2021.10.13
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class point{
public:
    int x, y, d, b;
    bool day;
    point(int X, int Y, int D, int B, bool _day){
        x = X; y = Y; d = D; b = B; day = _day;
    }
};

int n, m, k;
int a[1000][1000];
bool check[1000][1000][10][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isIn(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

int bfs(){
    queue<point> q;
    q.push(point(0, 0, 1, 0, 1));
    check[0][0][0][1] = true;
    while(!q.empty()){
        point node = q.front(); q.pop();
        bool isWall = false;
        if(node.x == n-1 && node.y == m-1) return node.d;
        for(int i = 0; i < 4; i++){
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(isIn(nx, ny) && check[nx][ny][node.b][node.day] == false){
                if(a[nx][ny] == 1 && node.b < k){
                    if(node.day){
                        check[nx][ny][node.b][node.day] = true;
                        q.push(point(nx, ny, node.d+1, node.b+1, !(node.day)));
                    }
                    isWall = true;
                }else if(a[nx][ny] == 0){
                    check[nx][ny][node.b][node.day] = true;
                    q.push(point(nx, ny, node.d+1, node.b, !(node.day)));
                }
            }
        }
        if(isWall && check[node.x][node.y][node.b][node.day] == false) {
            check[node.x][node.y][node.b][node.day] = true;
            q.push(point(node.x, node.y, node.d+1, node.b, !(node.day)));
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