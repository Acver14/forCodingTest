//2021.12.01
#include<iostream>
#include<queue>
using namespace std;

struct shark{
    int x, y;
} typedef shark;

int n;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int a[20][20];
int dist[20][20] = {0, };
int minVal;
shark dest;

bool isIn(shark s){
    if(s.x < 0 || s.y < 0 || s.x >= n || s.y >= n) return false;
    return true;
}

void bfs(int size){
    queue<shark> q;
    q.push(dest);
    dist[dest.x][dest.y] = 0;
    while(!q.empty()){
        shark node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            shark next = {node.x+dx[i], node.y+dy[i]};
            if(isIn(next) && dist[next.x][next.y] == -1){
                if(a[next.x][next.y] > size) continue;
                dist[next.x][next.y] = dist[node.x][node.y] + 1;
                if(a[next.x][next.y] != 0 && a[next.x][next.y] < size){
                    if(minVal > dist[next.x][next.y]) {
                        minVal = dist[next.x][next.y];
                        dest = {next.x, next.y};
                    }
                    else if(minVal == dist[next.x][next.y]){
                        if(dest.x == next.x){
                            if(dest.y > next.y){
                                dest = {next.x, next.y}; 
                            }
                        }else if(dest.x > next.x){
                            dest = {next.x, next.y};
                        }
                    }
                }
                q.push(next);
            }
        }
    }
}

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = -1;
        }
    }
    minVal = 500;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 9) {
                dest = {i, j};
                a[i][j] = 0;
            }
        }
    }

    int size = 2;
    int eat = 0;
    int ans = 0;
    while(true){
        shark prev = dest;
        init();
        bfs(size);
        if(!(prev.x == dest.x && prev.y == dest.y)){
            eat++;
            a[dest.x][dest.y] = 0;
            if(eat == size) {
                size++;
                eat = 0;
            }
            ans += dist[dest.x][dest.y];
        }
        else break;
    }

    cout << ans;
}