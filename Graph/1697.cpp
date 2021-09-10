//2021.09.10
#include<iostream>
#include<queue>
using namespace std;
#define MAX 100001

int main(){
    int n, k;
    cin >> n >> k;
   
   int dist[MAX];
   fill(dist, dist+MAX, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == k) break;
        if(now-1 > -1 && dist[now-1] == -1){
            int next = now - 1;
            dist[next] = dist[now] + 1;
            q.push(next);
        }if(now+1 < MAX && dist[now+1] == -1){
            int next = now + 1;
            dist[next] = dist[now] + 1;
            q.push(next);
        }if(now*2 > -1 && now*2 < MAX && dist[now*2] == -1){
            int next = now * 2;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
    }
    cout << dist[k];
}