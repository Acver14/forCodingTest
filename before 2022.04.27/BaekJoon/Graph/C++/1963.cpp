//2021.12.03
#include<iostream>
#include<queue>
using namespace  std;

bool check[10000];
int dist[10000];

void init(){
    check[0] = check[1] = true;
    for (int i = 2; i < 10000; i++) check[i] = true;
	
	for (int i = 2; i * i < 10000; i++) {
		for (int k = i * i; k < 10000; k += i) {
			check[k] = false;
		}
	}
}

int toInt(string num){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        ret = ret * 10 + (num[i] -'0');
    }
    return ret;
}

bool isPossible(int num){
    if(num < 1000 || num > 9999) return false;
    return true;
}

int bfs(int start, int dest){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node == dest) return dist[node];
        for(int i = 0; i < 4; i++){
            string node_s = to_string(node);
            for(int j = 0; j < 10; j++){
                node_s[i] = j + '0';
                int next = toInt(node_s);
                if(check[next] && dist[next] == -1 && next > 999){
                    dist[next] = dist[node]+1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main(){
    int T;
    int start, dest;
    init();
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> start >> dest;
        for(int j = 0; j < 10000; j++) dist[j] = -1;
        int result = bfs(start, dest);
        if(result == -1) cout << "Impossible" << '\n';
        else cout << result << '\n';
    }
}