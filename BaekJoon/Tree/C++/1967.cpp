//2021.09.16
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
int dist = 0;
int dist_node = 0;

void bfs(int start){
    check[start] = true;
    queue<Node> q;
    q.push(Node(start, -1, 0));
    while(!q.empty()){
        Node node = q.front(); q.pop();
        if(dist < node.dist){
            dist = node.dist;
            dist_node = node.value;
        }
        for(Node i: v[node.value]){
            if(check[i.value] == false){
                check[i.value] = true;
                q.push(Node(i.value, i.cost, node.dist+i.cost));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++){
        int to, from, weight;
        cin >> to >> from >> weight;
        v[to].push_back(Node(from, weight, 0));
        v[from].push_back(Node(to, weight, 0));
        
    }
    bfs(1);
    fill_n(check, n+1, false);
    bfs(dist_node);
    cout << dist << '\n';
    
}