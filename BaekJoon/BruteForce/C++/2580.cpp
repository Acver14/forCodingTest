//2021.09.28
#include<iostream>
#include<vector>
#include<cstring>
#include<thread>
#include<chrono>
using namespace std;

#define n 9

int a[n][n];
vector<pair<int, int> > pos;
vector<vector<int> > possible(n);
vector<vector<bool> > possibleCheck(n);
int ans = 0;
int _size;

bool checkW(int w, int d){
    for(int i = 0; i < n; i++){
        if(a[i][w] == d) return false;
    }
    return true;
}
bool checkH(int h, int d){
    for(int i = 0; i < n; i++){
        if(a[h][i] == d) return false;
    }
    return true;
}
bool checkBox(int x, int y, int d){
    for(int i : possible[int(x/3)*3 + y/3]){
        if(i == d) return true;
    }
    return false;
}

void go(int x, int y, int cnt){
    if(_size == cnt-1){
        cout << '\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
        int idx = int(x/3)*3 + y/3;
        int len = possible[idx].size();
        for(int i = 0; i < len; i++){
            if(possibleCheck[idx][i] == false && checkH(x, possible[idx][i]) && checkW(y, possible[idx][i]) && a[x][y] == 0){
                a[x][y] = possible[idx][i];
                possibleCheck[idx][i] = true;
                int nx = pos[cnt].first;
                int ny = pos[cnt].second;
                go(nx, ny, cnt+1);
                a[x][y] = 0;
                possibleCheck[idx][i] = false;
            }
        }
}

int main(){
    bool check[3][10] = {false, };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) pos.push_back(make_pair(i, j));
            check[int(j/3)][a[i][j]] = true;
        }
        if(i == 2 || i == 5 || i == 8){
            int k = 0;
            for(; k < 3; k++){
                for(int t = 1; t < 10; t++){
                    if(check[k][t]) continue;
                    else {
                        possible[int(i/3) * 3 + k].push_back(t);
                    }
                }
            }
            memset(check, false, 30);
        }
    }
    for(int i = 0; i < n; i++){
        int vsize = possible[i].size();
        possibleCheck[i].resize(vsize, false);
    }
    _size = pos.size();
    int x = pos[0].first;
    int y = pos[0].second;
    go(x, y, 1);
}