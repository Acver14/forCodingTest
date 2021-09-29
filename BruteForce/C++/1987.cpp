//2021.09.29
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int r, c;
char a[20][20];
bool check[27] = {false, };
bool checkA[20][20] = {false, };
int ans = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

class pos{
public:
    int x, y, d;
    pos(int X, int Y, int D){
        x = X;
        y = Y;
        d = D;
    }
    pos(){
        x = y = d = 0;
    }
};

bool isInBoard(int x, int y){
    if(x < 0 || x >= r || x < 0 || y >= c) return false;
    return true;
}

void go(pos p){
    if(ans < p.d) ans = p.d;
    for(int i = 0; i < 4; i++){
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if(isInBoard(nx, ny) && check['A'-a[nx][ny]] == false){
            check['A'-a[nx][ny]] = true;
            go(pos(nx, ny, p.d+1));
            check['A'-a[nx][ny]] = false;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    go(pos(0, 0, 0));
    cout << ans-1;
}