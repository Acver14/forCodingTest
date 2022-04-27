//2021.09.23
#include<iostream>
#include<queue>
using namespace std;

class coin{
public:
    int x, y, cost;
    coin(int X, int Y, int c){
        x = X;
        y = Y;
        cost = c;
    }
    coin(){
        x = y = cost = 0;
    }
};

int a[20][20];
coin p[2];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool possibleMove(coin pos){
    if(pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= m) return false;
    if(a[pos.x][pos.y] == 0){
        return true;
    }
    return false;
}

int ansCheck(pair<coin, coin> pos){
    if(pos.first.x < 0 || pos.first.x >= n || pos.first.y < 0 || pos.first.y >= m){
        if(!(pos.second.x < 0 || pos.second.x >= n || pos.second.y < 0 || pos.second.y >= m)){
            return 0;
        }
    }
    if(pos.second.x < 0 || pos.second.x >= n || pos.second.y < 0 || pos.second.y >= m){
        if(!(pos.first.x < 0 || pos.first.x >= n || pos.first.y < 0 || pos.first.y >= m)){
            return 1;
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char input;
            cin >> input;
            switch (input)
            {
            case 'o':
                a[i][j] = 0;
                p[k] = coin(i, j, 0);
                k++;
                break;
            case '.':
                a[i][j] = 0;
                break;
            case '#':
                a[i][j] = -1;
                break;
            }
        }
    }

    bool posP[2] = {false, };
    queue<pair<coin, coin> > q;
    q.push(make_pair(p[0], p[1]));
    while(!q.empty()){
        pair<coin, coin> node = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pair<coin, coin> next = make_pair(coin(node.first.x+dx[i], node.first.y+dy[i], node.first.cost+1),
                                                coin(node.second.x+dx[i], node.second.y+dy[i], node.second.cost+1));
            int ans = ansCheck(next);
            switch(ans){
                case 0:
                    cout << next.first.cost;
                    return 0;
                case 1:
                    cout << next.second.cost;
                    return 0;
            }
            posP[0] = possibleMove(next.first);
            posP[1] = possibleMove(next.second);
            if(posP[0] == false && posP[1] == false) continue;
            if(!posP[0]) {
                next.first.x = node.first.x;
                next.first.y = node.first.y;
            }
            if(!posP[1]) {
                next.second.x = node.second.x;
                next.second.y = node.second.y;
            }
            if(next.first.cost > 10 || next.second.cost > 10) {
                cout << -1;
                return 0;
            }
            q.push(next);
        }
    }
}