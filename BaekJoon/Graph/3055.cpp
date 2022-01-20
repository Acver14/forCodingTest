//2021.11.30
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class pos{
public:
    int x, y, min;
    pos(int a, int b, int c){
        x = a;
        y = b;
        min = c;
    }
    pos(){x = 0; y = 0; min = 0;}
};

char a[50][50];
bool check[50][50];
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
int r, c;
vector<pos> water;
pos start;
pos dest;

bool isIn(pos p){
    if(p.x < 0 || p.y < 0 || p.x >= r || p.y >= c) return false;
    return true;
}

int bfs(){
    queue<pos> q;
    queue<pos> w;
    for(pos p: water){
        w.push(p);
    }
    q.push(start);
    check[start.x][start.y] = true;
    int now = start.min;
    while(!q.empty()){
        pos node = q.front(); q.pop();
        if(now != node.min){
            now = node.min;
            int wSize = w.size();
            for(int i = 0; i < wSize; i++){
                pos pw = w.front(); w.pop();
                for(int j = 0; j < 4; j++){
                    pos nw = pos(pw.x+dx[j], pw.y+dy[j], pw.min+1);
                    if(isIn(nw) && a[nw.x][nw.y] == '.'){
                        a[nw.x][nw.y] = '*';
                        w.push(nw);
                    }
                }
            }
        }
        if(node.x == dest.x && node.y == dest.y) return node.min;
        else if(a[node.x][node.y] == '*') continue;
        for(int i = 0; i < 4; i++){
            pos next = pos(node.x+dx[i], node.y+dy[i], node.min+1);
            if(isIn(next) && (a[next.x][next.y] == '.' || a[next.x][next.y] == 'D') && check[next.x][next.y] == false){
                q.push(next);
                check[next.x][next.y] = true;
            }
        }
        
    }
    return -1;
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'D') dest = pos(i, j, 0);
            else if(a[i][j] == 'S') start = pos(i, j, 0);
            else if(a[i][j] == '*') water.push_back(pos(i, j, 0));
        }
    }

    int result = bfs();
    if(result == -1) cout << "KAKTUS";
    else cout << result;
}