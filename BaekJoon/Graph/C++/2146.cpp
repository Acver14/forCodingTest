//2021.09.08
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

class point{
public:
    int x;
    int y;
    int color;
    int cost;
    point(int _x, int _y, int _c, int _cost){
        x = _x;
        y = _y;
        color = _c;
        cost = _cost;
    }
    bool operator==(const point& p){
        if(x == p.x && y == p.y) return true;
        else return false;
    }
};
int a[100][100];
bool check[100][100];
vector<point> startPoint;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cost = -1;
int n;

bool checkBoundary(int x, int y){
    if(x > -1 && x < n && y > -1 && y < n) return true;
    return false;
}

void findIsland(int x, int y, int color){
    a[x][y] = color;
    check[x][y] = true;
    for(int i = 0; i < 4; i++){
        if(!checkBoundary(x+dx[i], y+dy[i])) continue;
        if(check[x+dx[i]][y+dy[i]] == false && a[x+dx[i]][y+dy[i]] == 1){
            findIsland(x+dx[i], y+dy[i], color);
        }else if(a[x+dx[i]][y+dy[i]] == 0){
            point start(x, y, color, 0);
            if(find(startPoint.begin(), startPoint.end(), start) == startPoint.end()){
                startPoint.push_back(point(x, y, color, 0));
            }
        }
    }
}

void buildBridge(point p, int color){
    queue<point> q;
    check[p.x][p.y] = true;
    q.push(p);
    // cout << '\n' << "start : " << p.x << ' ' << p.y << '\n';
    while(!q.empty()){
        point node = q.front();
        q.pop();
        // if(node.color > color){
        //     if(cost == -1 || cost > node.cost){
        //         cost = node.cost;
        //     }
        // }
        for(int i = 0; i < 4; i++){
            if(!checkBoundary(node.x+dx[i], node.y+dy[i])) continue;
            point next = point(node.x+dx[i], node.y+dy[i], node.color, node.cost+1);
            if(check[next.x][next.y] == false && a[next.x][next.y] == 0){
                if(cost == -1 || cost > next.cost){
                    check[next.x][next.y] = true;
                    // cout << "move : " << next.x << ' ' << next.y << '\n';
                    q.push(next);
                }
            }
            else if(a[next.x][next.y] > node.color){
                if(cost == -1 || cost > node.cost){
                    cost = node.cost;
                }
            }
        }
    }

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
    int color = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1 && check[i][j] == false){
                findIsland(i, j, color);
                color++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            check[i][j] = false;
        }
    }

    for(point p: startPoint){
        buildBridge(p, p.color);    // 다리 놓기에서 멈춤
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                check[i][j] = false;
            }
        }
    }

    cout << cost << '\n';
    return 0;
}