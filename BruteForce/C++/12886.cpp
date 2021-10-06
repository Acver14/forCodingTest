//2021.10.06
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;


bool check[1000][1000][1000];
int n[3];

pair<int, int> cal(int x, int y){
    if(x < y){
        return make_pair(x+x, y-x);
    }else if(x > y){
        return make_pair(x-y, y+y);
    }else{
        return make_pair(x, y);
    }
}

bool go(){
    queue<num> q;
    q.push(n);
    while(!q.empty()){
        num node = q.front(); q.pop();
        if(node.a == node.b && node.b == node.c) return true;
        pair<int, int> p;
        if(node.a != node.b){
            p = cal(node.a, node.b);
            num next(p.first, p.second, node.c);

            if() {
                q.push(next);
                s.insert(next);
            }
        }
        if(node.b != node.c){
            p = cal(node.b, node.c);
            num next(node.a, p.first, p.second);
            if(s.find(next) == s.end()) {
                q.push(next);
                s.insert(next);
            }
        }
        if(node.c != node.a){
            p = cal(node.c, node.a);
            num next(p.second, node.b, p.first);
            if(s.find(next) == s.end()) {
                s.insert(next);
                q.push(next);
            }
        }
    }
    return false;
}

int main(){
    cin >> n[0] >> n[1] >> n[2];
    bool result = go();
    if(result) cout << 1;
    else cout << 0;
    return 0;
}