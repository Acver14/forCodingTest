//2021.12.07
#include<iostream>
#include<queue>
#include<set>
using namespace std;

struct num{
    long val;
    string path = "";
};

set<long> check;
char d[] = {'*', '+', '-', '/'};

long cal(int func, long num){
    switch (func)
    {
    case 1:
        num += num;
        break;
    case 2:
        num -= num;
        break;
    case 0:
        num *= num;
        break;
    case 3:
        num /= num;
    default:
        break;
    }
    return num;
}

bool bfs(long s, long t){
    queue<num> q;
    q.push({s, ""});
    check.insert(s);
    while(!q.empty()){
        num node = q.front(); q.pop();
        if(node.val == t) {
            cout << node.path;
            return true;
        }
        for(int i = 0; i < 3; i++){
            num next = {cal(i, node.val), node.path+d[i]};
            if(check.find(next.val) == check.end() && next.val > 0) {
                check.insert(next.val);
                q.push(next);
            }
        }
        if(node.val != 0){
            num next = {cal(3, node.val), node.path+d[3]};
            if(check.find(next.val) == check.end() && next.val > 0) {
                check.insert(next.val);
                q.push(next);
            }
        }
    }
    return false;
}

int main(){
    long s, t;
    cin >> s >> t;
    if(s == t) cout << 0;
    else{
        bool result = bfs(s, t);
        if(!result) cout << -1;
    }
    return 0;
}