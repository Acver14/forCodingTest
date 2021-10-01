//2021.10.01
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int v[101] = {0, };
int dist[101] = {0, };
void bfs(){
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i = 1; i < 7; i++){
            int next = node+i;
            if(next > 100) continue;
            if(v[next] != 0) {
                next = v[next];
            }
            if(dist[next] == -1){
                dist[next] = dist[node]+1;
                q.push(next);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < n+m; i++){
        int from, to;
        cin >> from >> to;
        v[from] = to;
    }
    fill_n(dist, 101, -1);
    bfs();
    cout << dist[100] << '\n';
    return 0;
}