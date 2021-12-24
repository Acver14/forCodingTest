//2021.12.24
#include<iostream>
#include<queue>
#include<set>
using namespace std;

string ans = "123456780";

struct check{
    string s;
    int cnt;
}typedef check;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1 ,1};
set<string> visited;

string swap(string str, int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return str;
}

void bfs(string s){
    queue<check> q;
    q.push({s, 0});
    visited.insert(s);
    while(!q.empty()){
        string node = q.front().s; int cnt = q.front().cnt; q.pop();
        if(node == ans) {
            cout << cnt;
            return;
        }
        int x, y;
        for(int i = 0; i < 9; i++){
            if(node[i] == '0'){
                x = i % 3;
                y = i / 3;
                break;
            }
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            string str = swap(node, y*3+x, ny*3+nx);
            if(visited.find(str) != visited.end()) continue;
            q.push({str, cnt+1});
            visited.insert(str);
        }
    }
    cout << -1;
    return;
}

int main(){
    string s;
    for(int i = 0; i < 9; i++){
        char a;
        cin >> a;
        s.push_back(a);
    }

    bfs(s);
}