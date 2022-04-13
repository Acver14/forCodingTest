//2021.09.02
#include<iostream>
#include<algorithm>
using namespace std;

int w, h;
int a[52][52];
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

int dfs(int x, int y, int cnt){
    a[x][y] = 2;
    cnt++;
    for(int i = 0; i < 8; i++){
        if(a[x+dx[i]][y+dy[i]] == 1){
            cnt = dfs(x+dx[i], y+dy[i], cnt+1);
        }
    }
    return cnt;
}

int main(){
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                char temp;
                cin >> temp;
                a[i][j] = temp - '0';
            }
        }
        int num = 0;
        for(int i = 1; i < h+2; i++){
            int cnt = 0;
            for(int j = 1; j < w+2; j++){
                if(a[i][j] == 1) {
                    cnt = dfs(i, j, 0);
                    if(cnt > 0) num++;
                }
            }
        }
        for(int i = 0; i < h+3; i++){
            for(int j = 1; j < w+3; j++){
                a[i][j] = 0;
            }
        }
        cout << num << '\n';
    }

}