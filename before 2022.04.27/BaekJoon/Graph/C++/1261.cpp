//2021.09.13
#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[100][100];

class point{
public:
    int x;
    int y;
    int cost;
    point(int a, int b, int c){
        x = a;
        y = b;
        cost = c;
    }
};

bool isPossible(int x, int y){
    if(x > -1 && x < n && y > -1 && y < m){
        return !check[x][y];
    }
    return false;
}

int main(){
    int ans = -1;
    int a[100][100];
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char input;
            cin >> input;
            a[i][j] = input - '0';
        }
    }

    deque<point> q;
    q.push_front(point(0, 0, 0));
    check[0][0] = true;
    while(!q.empty()){
        point node = q.front(); q.pop_front();
        if(node.x == n-1 && node.y == m-1) {
            cout << node.cost;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            if(isPossible(node.x+dx[i], node.y+dy[i])){
                point next(node.x+dx[i], node.y+dy[i], node.cost+a[node.x+dx[i]][node.y+dy[i]]);
                if(a[next.x][next.y] == 1){
                    q.push_back(next);
                }else{
                    q.push_front(next);
                }
                check[next.x][next.y] = true;
            }
        }
    }
}