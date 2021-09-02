//2021.09.02
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int a[102][102];
bool check[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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

int bfs(int x, int y, int cnt){
    a[x][y] = 2;
    queue<point> q;
    q.push(point(x, y, 1));
    while(!q.empty()){
        point node = q.front();
        q.pop();
        if(node._x == n && node._y == m) return node._cost;
        for(int i = 0; i < 4; i++){
            int nextX = node._x + dx[i];
            int nextY = node._y + dy[i];
            if(a[nextX][nextY] == 1){
                a[nextX][nextY] = 2;
                cnt++;
                q.push(point(nextX, nextY, node._cost+1));
            }
        }
    }
    return -1;
}
// bfs를 이용한 최단 거리 찾기의 경우, DP처럼 구현해야함
// 이때, point 클래스에 cost값을 넣지 않고 bfs 지역 변수 cnt를 이용하여 방문 횟수를 기록할 경우, 결국 bfs를 통한 전체 방문 횟수가 기록됨
// 고로 각 노드까지의 최단 거리를 기록한 point._cost를 이용해 최단 거리를 구함
// 다시 한번, cnt를 이용할 경우 cnt에는 for문에 걸려 해당 노드에서 갈 수 있는 모든 값을 방문 후 그 횟수가 cnt에 더해지는데, 반면 위 코드처럼 point._cost를 이용할 경우,
// for문에 몇번 들어가든 옮겨진 노드까지의 방문값은 이전 노드의 방문값 + 1이 되어 항상 최소값을 유지할 수 있음

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    cout << bfs(1, 1, 0);
}