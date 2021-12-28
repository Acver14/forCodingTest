//2021.12.28
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct bucket{
    int a, b, c;
}typedef bucket;

int a, b, c;
bool check[201][201][201];
vector<int> ans;

bucket move(int idx, bucket B){
    int temp;
    switch(idx){
        case 0:
            temp = B.a + B.c;
            if(temp > a) {
                B.c = temp - a;
                B.a = a;
            }
            else{
                B.a = temp;
                B.c = 0;
            }
            break;
        case 1:
            temp = B.b + B.c;
            if(temp > b) {
                B.c = temp - b;
                B.b = b;
            }
            else{
                B.b = temp;
                B.c = 0;
            }
            break;
        case 2:
            temp = B.a + B.c;
            if(temp > c) {
                B.a = temp - c;
                B.c = c;
            }
            else{
                B.c = temp;
                B.a = 0;
            }
            break;
        case 3:
            temp = B.b + B.c;
            if(temp > c) {
                B.b = temp - c;
                B.c = c;
            }
            else{
                B.c = temp;
                B.b = 0;
            }
            break;
        case 5:
            temp = B.a + B.b;
            if(temp > a) {
                B.b = temp - a;
                B.a = a;
            }
            else{
                B.b = 0;
                B.a = temp;
            }
            break;
        case 6:
            temp = B.a + B.b;
            if(temp > b) {
                B.a = temp - b;
                B.b = b;
            }
            else{
                B.a = 0;
                B.b = temp;
            }
            break;
        default: break;
    }
    return B;
}

void bfs(){
    queue<bucket> q;
    q.push({0, 0, c});
    check[0][0][c] = true;
    while(!q.empty()){
        bucket node = q.front(); q.pop();
        if(find(ans.begin(), ans.end(), node.c) == ans.end() && node.a == 0) ans.push_back(node.c);
        for(int i = 0; i < 7; i++){
            bucket next = move(i, node);
            if(check[next.a][next.b][next.c] == true) continue;
            q.push(next);
            check[next.a][next.b][next.c] = true;
        }
    }
}

int main(){
    cin >> a >> b >> c;
    bfs();
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << ' ';
    }
}