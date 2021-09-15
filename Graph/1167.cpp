//2021.09.15
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int value;
    int cost;
    int dist;
    Node(int v, int c, int d){
        value = v; cost = c; dist = d;
    }
};

vector<Node> v[100001];
int n;
vector<int> leaf;
bool check[100001];

int bfs(int start){
    check[start] = true;
    queue<Node> q;
    q.push(Node(start, -1, 0));
    while(!q.empty()){
        Node node = q.front(); q.pop();
        for(Node i: v[node]){
            if(check[i.value] == false){
                check[i.value] = true;
                q.push(Node(i.value, i.cost, i.dist+node.cost));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        while(true){
            int to, value;
            cin >> to;
            if(to == -1) break;
            cin >> value;
            v[t].push_back(Node(to, value, 0));
            cnt[t]++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i]==1) leaf.push_back(i);
    }

    
}