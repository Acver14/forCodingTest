//2021.09.05
//2021.09.06 retry
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> v[100001];
vector<int> visited;
int dist[100001];
bool check[100001];
int n;

int indexOfVisited(int dest){
    return find(visited.begin(), visited.end(), dest) - visited.begin(); 
}

bool findCircle(int start, int prev){
    check[start] = true;
    visited.push_back(start);
    for(int i: v[start]){
        bool endFlag = false;
        for(int j: visited){
            if(prev != j && i == j){
                visited.erase(visited.begin(), find(visited.begin(), visited.end(), j));
                visited.erase(find(visited.begin(), visited.end(), start)+1, visited.end());
                for(int k = 1; k <= n; k++){
                    bool end = false;
                    int size = v[k].size();
                    for(int x = 0; x < size; x++){
                        for(int t : visited){
                            if(v[k][x] == t){
                                v[k][x] = 0;
                                if(!end){
                                    v[0].push_back(k);
                                    end = true;
                                }
                                
                            }
                        }
                    }
                }
                return true;
            }
        }
        if(!check[i]){
            check[i] = true;
            if(findCircle(i, start)) return true;
        }
    }
    visited.pop_back();
    return false;
}

void calDist(){
    queue<int> q;
    int start = 0;
    q.push(start);
    check[start] = true;
    for(int i: visited){
        check[i] = true;
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i: v[node]){
            if(!check[i]){
                check[i] = true;
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int to, from;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    check[0] = true;
    findCircle(1, 0);
    fill_n(check, n+2, false);
    calDist();
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}