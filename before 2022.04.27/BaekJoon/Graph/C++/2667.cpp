//2021.09.02
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int a[27][27];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> complex;

void printA(){
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            cout << a[i][j] <<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int dfs(int x, int y, int c, int cnt){
    a[x][y] = c;
    for(int i = 0; i < 4; i++){
        if(a[x+dx[i]][y+dy[i]] == 1){
            cnt = dfs(x+dx[i], y+dy[i], c, cnt+1);
        }
    }
    return cnt;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char temp;
            cin >> temp;
            a[i][j] = temp - '0';
        }
    }

    int num = 2;
    for(int i = 1; i < n+2; i++){
        for(int j = 1; j < n+2; j++){
            int cnt = 0;
            if(a[i][j] == 1) {
                cnt = dfs(i, j, num, 1);
                num++;
                complex.push_back(cnt);
            }
        }
    }

    sort(complex.begin(), complex.end());
    cout << num-2 << '\n';
    for(int i: complex){
        cout << i << '\n';
    }

}