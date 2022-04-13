//2021.12.21
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

struct pack{
    int x, y;
    string ans = "";
}typedef pack;

int n, m;
char a[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char d[] = {'N', 'S', 'W', 'E'};
int check[50][50][50][50] = {0, };
vector<pack> p;

void bfs(){
    queue<pair<pack, pack> > q;
    q.push({p[0], p[1]});
    while(!q.empty()){
        pack node1 = q.front().first;
        pack node2 = q.front().second;
        q.pop();
        if(node1.x == node2.x && node1.y == node2.y) {
            cout << check[node1.x][node1.y][node2.x][node2.y]-1 << ' ' << node1.ans << '\n';
            return;
        }
        for(int i = 0; i < 4; i++){
            pack next1 = {node1.x+dx[i], node1.y+dy[i], node1.ans+d[i]};
            pack next2 = {node2.x+dx[i], node2.y+dy[i], node2.ans+d[i]};
            if(next1.x < 0) next1.x = n-1;
            else if(next1.x >= n) next1.x = 0;
            if(next1.y < 0) next1.y = m-1;
            else if(next1.y >= m) next1.y = 0;
            if(next2.x < 0) next2.x = n-1;
            else if(next2.x >= n) next2.x = 0;
            if(next2.y < 0) next2.y = m-1;
            else if(next2.y >= m) next2.y = 0;
            if(a[next1.x][next1.y] == 'G' || a[next2.x][next2.y] == 'G') continue;
            if(a[next1.x][next1.y] == 'X'){
                next1.x = node1.x; next1.y = node1.y;
            }
            if(a[next2.x][next2.y] == 'X'){
                next2.x = node2.x; next2.y = node2.y;
            }
            if(check[next1.x][next1.y][next2.x][next2.y] > check[node1.x][node1.y][node2.x][node2.y]+1){
                check[next1.x][next1.y][next2.x][next2.y] = check[node1.x][node1.y][node2.x][node2.y]+1;
                q.push({next1, next2});
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> a[j][k];
                if(a[j][k] == 'P'){
                    a[j][k] = '.';
                    p.push_back({j, k, ""});
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                for(int s = 0; s < n; s++){
                    for(int l = 0; l < m; l++){
                        check[j][k][s][l] = 210000000;
                    }
                }
            }
        }
        check[p[0].x][p[0].y][p[1].x][p[1].y] = 1;
        bfs();
        p.clear();
    }

}