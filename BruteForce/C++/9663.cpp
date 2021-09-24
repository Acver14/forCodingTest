//2021.09.24
// 퀸이 공격하지 못 하는 경우
// x 가 동일
// y 가 동일
// 대각선에 위치할 때 -> x와 y의 차이값이 동일할 때
#include<iostream>
#include<vector>
using namespace std;

bool board[15][15] = {false, };
int n;
bool posX[15] = {false, };
bool posY[15] = {false, };
int ans = 0;
int cnt = 0;

bool checkQ(int x, int y){
    if(posX[x] || posY[y]) return false;
    return true;
}

void go(){
    if(cnt == n) {
        ans++;
        cout << ans << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == false && checkQ(i,j)){
                cout << i << ' ' << j << '\n';
                board[i][j] = true;
                posX[i] = posY[j] = true;
                int k = 1;
                int t = 1;
                while(true){
                    bool flag = false;
                    if(i-k > -1 && j-t > -1) {
                        board[i-k][j-t] = true;
                        flag = true;
                    }
                    if(i+k < n && j+t < n) {
                        board[i+k][j+t] = true;
                        flag = true;
                    }
                    k++; t++;
                    if(flag == false) break;
                }
                cnt++;
                go();
                cnt--;
                board[i][j] = false;
                while(true){
                    bool flag = false;
                    if(i-k > -1 && j-t > -1) {
                        board[i-k][j-t] = false;
                        flag = true;
                    }
                    if(i+k < n && j+t < n) {
                        board[i+k][j+t] = false;
                        flag = true;
                    }
                    if(flag == false) break;
                }
                posX[i] = posY[j] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    go();
    cout << ans;
}