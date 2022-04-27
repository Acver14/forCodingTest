//2021.09.30
#include<iostream>
#include<vector>
using namespace std;

char a[10][10];
int n, m;
int cnt = 0;
int ans = 0;

class pos{
public:
    int x, y;
    char c;
    pos(int X, int Y, char C){
        x = X;
        y = Y;
        c = C;
    }
    pos(){
        x = y = c = 0;
    }
};

pos R, B;

int moveLeft(pos r, pos b){
    int l = 1;
    while(true){
        bool flag = false;
        int rPos, bPos;
        if(a[r.x][r.y-l] == '0' && a[b.x][b.y-l] == '0') return 3;
        if(a[r.x][r.y-l] == '.'){
            flag = true;
        }
        else if(a[r.x][r.y] == '0'){
            return 1;
        }
        else{
            rPos = r.y-l;
        }
        if(a[b.x][b.y-l] == '.'){
            flag = true;
        }
        else if(a[b.x][b.y-l] == '0'){
            return 2;
        }
        else{
            bPos = b.y-l;
        }
        l++;
        if(!flag) {
            a[r.x][r.y] = a[b.x][b.y] = '.';
            a[r.x][rPos] = 'R';
            a[r.x][bPos] = 'B';
            R.y = rPos;
            B.y = bPos;
            return 0;
        }
    }
}
int moveRight(pos r, pos b){
    int l = 1;
    while(true){
        bool flag = false;
        int rPos, bPos;
        if(a[r.x][r.y+l] == '0' && a[b.x][b.y+l] == '0') return 3;
        if(a[r.x][r.y+l] == '.'){
            flag = true;
        }
        else if(a[r.x][r.y] == '0'){
            return 1;
        }
        else{
            rPos = r.y+l;
        }
        if(a[b.x][b.y+l] == '.'){
            flag = true;
        }
        else if(a[b.x][b.y+l] == '0'){
            return 2;
        }
        else{
            bPos = b.y+l;
        }
        l++;
        if(!flag) {
            a[r.x][r.y] = a[b.x][b.y] = '.';
            a[r.x][rPos] = 'R';
            a[r.x][bPos] = 'B';
            R.y = rPos;
            B.y = bPos;
            return 0;
        }
    }
}
int moveTop(pos r, pos b){
    int l = 1;
    while(true){
        bool flag = false;
        int rPos, bPos;
        if(a[r.x-l][r.y] == '0' && a[b.x-l][b.y] == '0') return 3;
        if(a[r.x-l][r.y] == '.'){
            flag = true;
        }
        else if(a[r.x-l][r.y] == '0'){
            return 1;
        }
        else{
            rPos = r.x-l;
        }
        if(a[b.x-l][b.y] == '.'){
            flag = true;
        }
        else if(a[b.x-l][b.y] == '0'){
            return 2;
        }
        else{
            bPos = b.x-l;
        }
        l++;
        if(!flag) {
            a[r.x][r.y] = a[b.x][b.y] = '.';
            a[rPos][r.y] = 'R';
            a[bPos][b.y] = 'B';
            R.x = rPos;
            B.x = bPos;
            return 0;
        }
    }
}
int moveBottom(pos r, pos b){
    int l = 1;
    while(true){
        bool flag = false;
        int rPos, bPos;
        if(a[r.x+l][r.y] == '0' && a[b.x+l][b.y] == '0') return 3;
        if(a[r.x+l][r.y] == '.'){
            flag = true;
        }
        else if(a[r.x][r.y] == '0'){
            return 1;
        }
        else{
            rPos = r.x+l;
        }
        if(a[b.x+l][b.y] == '.'){
            flag = true;
        }
        else if(a[b.x+l][b.y] == '0'){
            return 2;
        }
        else{
            bPos = b.x+l;
        }
        l++;
        if(!flag) {
            a[r.x][r.y] = a[b.x][b.y] = '.';
            a[rPos][r.y] = 'R';
            a[bPos][b.y] = 'B';
            R.x = rPos;
            B.x = bPos;
            return 0;
        }
    }
}

int move(pos r, pos b, int dir){
    switch(dir){
        case 0:
            return moveLeft(r, b);
        case 1:
            return moveRight(r, b);
        case 2:
            return moveTop(r, b);
        case 3:
            return moveBottom(r, b);
    }
}

void go(){
    for(int i = 0; i < 4; i++){
        int result = move(R, B, i);
        cout << result << '\n';
        if(result == 1){
            if(ans > cnt) ans = cnt;
            cout << cnt << '\n';
            exit(0);
            return;
        }
        else if(result == 0){
            cnt++;
            go();
        }
        else{
            cnt--;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R') R = pos(i, j, 'R');
            if(a[i][j] == 'B') B = pos(i, j, 'B');
        }
    }
    go();
    cout << ans;
}