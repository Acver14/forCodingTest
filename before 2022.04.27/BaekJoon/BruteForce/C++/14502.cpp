//2021.10.06
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class point{
public:
    int x, y;
    point(int X, int Y){
        x = X;
        y = Y;
    }
};

const int wall = 3;
int n, m;
int a[8][8];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check[8][8] = {false, };
int non_safe = 0;
int ans = -1;
vector<point> virus;

bool isIn(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void bfs(){
    int cnt = 0;
    queue<point> q;
    for(point v: virus){
        q.push(v);
    }
    while(!q.empty()){
        point node = q.front();
        int x = node.x; int y = node.y;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isIn(nx, ny)){
                if(check[nx][ny] == false && a[nx][ny] == 0){
                    check[nx][ny] = true;
                    q.push(point(nx, ny));
                    cnt++;
                }
            }
        }
    }
    if(ans == -1 || ans > cnt) ans = cnt;
}

void resetCheck(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = false;
        }
    }
}

void buildWall(int cnt){
    if(cnt == wall){
        bfs();
        resetCheck();
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != 0) continue;
            a[i][j] = 1;
            buildWall(cnt+1);
            a[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virus.push_back(point(i, j));
            if(a[i][j] != 0) non_safe++;
        }
    }
    buildWall(0);
    cout << n*m - ans - non_safe - wall;
}