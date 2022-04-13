//2021.09.10
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int main(){
    int s;
    int imo[1001][1001];
    bool check[1001];

    cin >> s;

    memset(imo, -1, sizeof(imo));
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    check[1] = true;
    imo[1][0] = 0;
    while(!q.empty()){
        int now_s = q.front().first;
        int now_c = q.front().second;
        q.pop();
        int addDist = imo[now_s][now_c] + 1;
        if(imo[now_s][now_s] == -1){
            imo[now_s][now_s] = addDist;
            q.push(make_pair(now_s, now_s));
        }
        if(now_s+now_c <= s && imo[now_s+now_c][now_c] == -1){
            imo[now_s+now_c][now_c] = addDist;
            q.push(make_pair(now_s+now_c, now_c));
        }
        if(now_s > 0 && imo[now_s-1][now_c] == -1){
            imo[now_s-1][now_c] = addDist;
            q.push(make_pair(now_s-1, now_c));
        }
    }
    int ans = -1;
    for(int i = 1; i <= s; i++){
        if((ans > imo[s][i] && imo[s][i] != -1) || ans == -1) ans = imo[s][i];
    }
    cout << ans << '\n';
    return 0;
}