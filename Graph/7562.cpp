//2021.09.03
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class point{
public:
    int _x;
    int _y;
    int _cost;
    point(int x, int y, int cost){
        _x = x;
        _y = y;
        _cost = cost;
    }
};

bool a[300][300];
int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

bool checkInMap(point p){
    for(int i = 0; i < 8; i++){
        if(p._x < 0 || p._x > 299 || p._y > 299 || p._y < 0) return false;
    }
    return true;
}

int bfs(point from, point to){
    a[from._x][from._y] = true;
    queue<point> q;
    q.push(from);
    int ret = 0;
    while(!q.empty()){
        point node = q.front();
        q.pop();
        if(node._x == to._x && node._y == to._y) {
            ret = node._cost;
            break;
        }
        for(int i = 0; i < 8; i++){
            point next(node._x + dx[i], node._y + dy[i], node._cost+1);
            if(!checkInMap(next)) continue;
            if(a[next._x][next._y] == false){
                a[next._x][next._y] = true;
                q.push(next);
            }
        }
    }
    return ret;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = false;
            }
        }
        int toX, toY, fromX, fromY;
        cin >> fromX >> fromY;
        cin >> toX >> toY;
        cout << bfs(point(fromX, fromY, 0), point(toX, toY, 0)) << '\n';
    }

}