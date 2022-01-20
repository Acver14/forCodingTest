//2021.10.08
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class point{
public:
    int x, y;
    bool broken;
    point(int X, int Y){
        x = X;
        y = Y;
    }
    point(){
    }
};

int a[1000][1000];
int check[1000][1000];
int n, m;
vector<point> wall;
vector<int> len;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isIn(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void bfs(int x, int y, int flag){
    queue<point> q;
    q.push(point(x, y));
    a[x][y] = flag;
    while(!q.empty()){
        point node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(isIn(nx, ny) && a[nx][ny] == 0){
                q.push(point(nx, ny));
                a[nx][ny] = flag;
                len[flag*(-1)]++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            a[i][j] = input[j]-'0';
            if(a[i][j] == 1) wall.push_back(point(i, j));
        }
    }
    len.push_back(0);
    int flag = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                len.push_back(1);
                bfs(i, j, flag);
                flag -= 1;
            }
        }
    }
    vector<bool> sumCheck(flag*(-1), false);
    for(point p: wall){
        for(int i = 0; i < 4; i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(isIn(nx, ny)){
                if(a[nx][ny] < 0 && sumCheck[a[nx][ny]*(-1)] == false) {
                    a[p.x][p.y] += len[a[nx][ny]*(-1)]%10;
                    sumCheck[a[nx][ny]*(-1)] = true;
                }
            }
        }
        sumCheck.assign(flag*(-1), false);
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] < 0) ans += '0';
            else ans += '0' + a[i][j]%10;
        }
        ans += '\n';
    }

    cout << ans;
}