//2021.09.10
#include<iostream>
#include<deque>
using namespace std;
#define MAX 100001

int main(){
    int n, k;
    cin >> n >> k;
   
   int dist[MAX];
   fill(dist, dist+MAX, -1);
    
    deque<int> q;
    q.push_back(n);
    dist[n] = 0;
    int cnt = 0;
    while(!q.empty()){
        int now = q.front(); q.pop_front();
        if(now*2 < MAX && dist[now*2] == -1){
            int next = now * 2;
            dist[next] = dist[now];
            q.push_front(next);
        }
        if(now-1 > -1 && dist[now-1] == -1){
            int next = now - 1;
            dist[next] = dist[now] + 1;
            q.push_back(next);
        }if(now+1 < MAX && dist[now+1] == -1){
            int next = now + 1;
            dist[next] = dist[now] + 1;
            q.push_back(next);
        }
    }
    cout << dist[k];
}