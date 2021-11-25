#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class point{
public:
    int x, y, sec;
    point(){
        x = y = sec = -1;
    }
    point(int a, int b, int c){
        x = a;
        y = b;
        sec = c;
    }
};

char board[8][8];
bool check[8][8];
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1, 0};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1, 0};
bool existWall = true;

bool isPossible(point p){
    if(p.x < 0 || p.y < 0 || p.x > 7 || p.y > 7 || board[p.x][p.y] == '#') return false;
    return true;
}

void moveWall(){
    existWall = false;
    for(int j = 7; j > -1; j--){
        if(board[7][j] == '#') board[7][j] = '.';
    }
    for(int i = 6; i > -1 ; i--){
        for(int j = 7; j > -1; j--){
            if(board[i][j] == '#'){
                board[i][j] = '.';
                board[i+1][j] = '#';
                existWall = true;
            }
        }
    }
}

bool bfs(){
    queue<point> q;
    q.push(point(7, 0, 0));
    int now = 0;
    while(!q.empty()){
        point node = q.front();
        q.pop();
        if(now != node.sec){
            now = node.sec;
            if(existWall) moveWall();
        }
        if(board[node.x][node.y] == '#') continue;
        if(node.x == 0 && node.y == 7) return true;
        for(int i = 0; i < 9; i++){
            point next = point(node.x+dx[i], node.y+dy[i], node.sec+1);
            if(isPossible(next)){
                if(existWall) q.push(next);
                else {
                    if(check[next.x][next.y]) continue;
                    check[next.x][next.y] = true;
                    q.push(next);
                }
            }
        }   
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }
    bool result = bfs();
    if(result) cout << 1;
    else cout << 0;
}