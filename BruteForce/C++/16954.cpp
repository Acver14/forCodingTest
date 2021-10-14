//2021.10.14
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class point{
public:
    int x, y, sec;
    point(int X, int Y, int S){
        x = X; y = Y, sec = S;
    }
};

const int n = 8;
char a[8][8];
vector<pair<int, int> > wall;
bool check[8][8][8];

int dx[] = {-1, 1, -1, 1, 1, -1, 0, 0};
int dy[] = {0, 0, -1 ,1, -1, 1, -1, 1};

void moveWall(){
    int size = wall.size();
    cout << "size : " << size << '\n';
    for(int i = 0; i < size; i++){
        cout << wall[i].first+1 << ' ' << wall[i].second << ' ' << n << '\n';
        a[wall[i].first][wall[i].second] = '.';
        if(wall[i].first+1 < n) {
            wall[i].first = wall[i].first+1;
            // a[wall[i].first+1][wall[i].second] = '#';
        }
        else wall.erase(wall.begin()+i);
    }
}

bool isIn(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

int bfs(){
    queue<point> q;
    q.push(point(7,0,0));
    int now = 0;
    int sec = 0;
    while(!q.empty()){
        point node = q.front(); q.pop();
        // cout << sec << ' ' << node.x << ' ' << node.y << '\n';
        if(now != node.sec && !wall.empty()){
            moveWall();
            now = node.sec;
            sec = node.sec;
        }
        if(a[node.x][node.y] == '#') continue;
        if(node.x == 0 && node.y == 7) return 1;
        for(int i = 0; i < 8; i++){
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if(isIn(nx, ny) && check[nx][ny][sec] == false){
                check[nx][ny][sec] = true;
                q.push(point(nx, ny, node.sec+1));
            }
        }
        q.push(point(node.x, node.y, node.sec+1));
    }
    return 0;
}


int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == '#') wall.push_back(make_pair(i, j));
        }
    }
    for(auto w: wall){
        cout << w.first << ' ' << w.second << '\n';
    }
    cout << wall.size() << '\n';
    int result = bfs();
    cout << result;
    return 0;
}