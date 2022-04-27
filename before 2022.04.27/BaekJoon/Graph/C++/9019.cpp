//2021.10.05
#include<iostream>
#include<queue>
using namespace std;

char cmd[10000] = { 0, };
int path[10000] = { 0, };
string ans = "";

int cal(int v, int cmd){
    switch(cmd){
        case 0:
            return (2 * v) % 10000;
        case 1:
            return v  == 0 ? 9999 : v - 1;
        case 2:
            if (v >= 1000) {
                int t = v / 1000;
                v *= 10;
                v -= t * 10000;
                v += t;
                return v;
            }else
                return v*10;
        case 3:
            int low = v % 10;
            v /= 10;
            v += low * 1000;
            return v;
    }

    return v;
}

void bfs(int start, int dest){
    queue<int> q;
    q.push(start);
    path[start] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node == dest) return;
        for(int i = 0; i < 4; i++){
            int next = cal(node, i);
            if(path[next] != -1) continue;
            q.push(next);
            path[next] = node;
            switch(i){
                case 0:
                    cmd[next] = 'D';
                    break;
                case 1:
                    cmd[next] = 'S';
                    break;
                case 2:
                    cmd[next] = 'L';
                    break;
                case 3:
                    cmd[next] = 'R';
            }
        }
    }
}

void print(int start, int dest){
    if(dest == start) return;
    print(start, path[dest]);
    ans += cmd[dest];
    return;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        fill_n(path, 10000, -1);
        fill_n(cmd, 10000, 0);
        int start, dest;
        cin >> start >> dest;
        bfs(start, dest);
        print(start, dest);
        cout << ans << '\n';
        ans = "";
    }
}