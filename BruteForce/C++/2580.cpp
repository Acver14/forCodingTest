//2021.09.28
#include<iostream>
#include<vector>
using namespace std;

#define n 9

int a[n][n];
vector<pair<int, int> > pos;
vector<vector<int> > possible(n);
int cnt = 0;
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


void go(int x, int y){
    if(_size == cnt){
        return;
    }

}

int main(){
    bool check[3][9] = {false, };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) pos.push_back(make_pair(i, j));
            check[int(j/n)][a[i][j]] = true;
        }
        if(i == 2 || i == 5 || i == 8){
            int k = 0;
            for(; k < 3; k++){
                for(int t = 0; t < 9; t++){
                    if(check[k][t]) continue;
                    else possible[int(i/n) * 3 + k].push_back(t+1);
                }
            }
            memset(check, false, 27);
        }
    }
    _size = pos.size();
    for(auto i: pos){
        cout << i.first << ' ' << i.second << '\n';
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j: possible[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }
}