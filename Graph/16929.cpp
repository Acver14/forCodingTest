//2021.09.03
#include<iostream>
using namespace std;

class point{
public:
    int _x;
    int _y;
    point(int x, int y){
        _x = x;
        _y = y;
    }
};

int a[51][51];
int n, m;
bool check[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool checkPoint(point p){
    for(int i = 0; i < 4; i++){
        if(p._x >= n || p._x < 0 || p._y >= m || p._y < 0) return false;
    }
    return true;
}

bool dfs(point start, point x, int c, int cnt){
    a[x._x][x._y] = 0;
    for(int i = 0; i < 4; i++){
        if(cnt > 2){
            if(start._x == x._x+dx[i] && start._y == x._y+dy[i]) return true;
        }
        if(!checkPoint(x)) continue;
        if(a[x._x+dx[i]][x._y+dy[i]] == c){
            a[x._x+dx[i]][x._y+dy[i]] = 0;
            return dfs(start, point(x._x+dx[i], x._y+dy[i]), c, cnt+1);
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int A[51][51];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            a[i][j] = c - 'A' + 1;
            A[i][j] = a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] > 0){
                point p(i, j);
                bool result = dfs(p, p, a[i][j], 0);
                if(result) {
                    cout << "Yes" << '\n';
                    return 0;
                }
                for(int l = 0; l < n; l++){
                    for(int k = 0; k < m; k++){
                        a[l][k] = A[l][k];
                    }
                }
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}