//2021.10.06
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class num{
public:
    int a[3];
    num(){}
    num(int A, int B, int C){
        a[0] = A; a[1] = B; a[2] = C;
        sort(a, a+3);
    }
};

bool check[1501][1501];
num n;

pair<int, int> cal(int x, int y){
    return make_pair(x+x, y-x);
}

bool go(){
    queue<num> q;
    q.push(n);
    check[n.a[0]][n.a[2]] = true;
    while(!q.empty()){
        num node = q.front(); q.pop();
        if(node.a[0] == node.a[1] && node.a[1] == node.a[2]) return true;
        pair<int, int> p;
        if(node.a[0] != node.a[1]){
            p = cal(node.a[0], node.a[1]);
            num next(p.first, p.second, node.a[2]);
            if(!check[next.a[0]][next.a[2]]) {
                q.push(next);
                check[next.a[0]][next.a[2]] = true;
            }
        }
        if(node.a[1] != node.a[2]){
            p = cal(node.a[1], node.a[2]);
            num next(node.a[0], p.first, p.second);
            if(!check[next.a[0]][next.a[2]]) {
                q.push(next);
                check[next.a[0]][next.a[2]] = true;
            }
        }
        if(node.a[0] != node.a[2]){
            p = cal(node.a[0], node.a[2]);
            num next(node.a[1], p.first, p.second);
            if(!check[next.a[0]][next.a[2]]) {
                q.push(next);
                check[next.a[0]][next.a[2]] = true;
            }
        }
    }
    return false;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    n = num(a, b, c);
    bool result = go();
    if(result) cout << 1;
    else cout << 0;
    return 0;
}