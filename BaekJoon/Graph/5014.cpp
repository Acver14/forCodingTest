//2022.01.10
#include<iostream>
#include<queue>
using namespace std;

int f, s, g, elevate[2];
int check[1000001];

int main(){
    cin >> f >> s >> g >> elevate[0] >> elevate[1];
    elevate[1] = elevate[1] * (-1);

    for(int i = 0; i <= f; i++){
        check[i] = -1;
    }

    queue<int> q;
    q.push(s);
    check[s] = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i = 0; i < 2; i++){
            int next = node + elevate[i];
            if(next < 1 || next > f) continue;
            if(check[next] == -1 || check[next] > check[node]+1){
                check[next] = check[node]+1;
                q.push(next);
            }
        }
    }
    if(check[g] == -1) cout << "use the stairs" << '\n';
    else cout << check[g] << '\n';
}