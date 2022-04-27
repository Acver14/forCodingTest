//2021.09.03
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class point{
public:
    int _x;
    int _y;
    int _cost;
    point(){
        _x = _y = _cost = 0;
    }
    point(int x, int y, int cost){
        _x = x;
        _y = y;
        _cost = cost;
    }
};

int n ,m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[1003][1003];
bool check = false;
vector<point> start;

bool checkMap(point x){
    int i = 0;
    for(; i < 4; i++){
        if(a[x._x + dx[i]][x._y + dy[i]] == -1) continue;
        else break;
    }
    if(i == 4) return false;
    else return true;
}

int bfs(){
    queue<point> q;
    for(point p: start){
        q.push(p);
        a[p._x][p._y] = 2;
    }
    int cost = 0;
    while(!q.empty()){
        point node = q.front();
        q.pop();
        int i = 0;
        for(; i < 4; i++){
            point next(node._x + dx[i], node._y + dy[i], node._cost + 1);
            if(a[next._x][next._y] == 0){
                a[next._x][next._y] = 2;
                q.push(next);
            }
        }
        if(cost < node._cost) cost = node._cost;
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> m >> n;
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            a[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) start.push_back(point(i, j, 0));
        }
    }
    int ans = 0;
    if(start.empty()){
        cout << -1 << '\n';
        return 0;
    }
    else{
        ans = bfs();
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}