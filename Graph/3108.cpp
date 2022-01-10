//2021.12.31
#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct rec{
    int x1, y1, x2, y2;
}typedef rec;

int n;
int a[1000];
int par[1001];
vector<rec> rect;

int find_parent(int x){
    if(par[x] == x) return x;
    return par[x] = find_parent(par[x]);
}

void make_union(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a < b) par[b] = a;
    else if(a > b) par[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;

    rect.push_back({0, 0, 0, 0});
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rect.push_back({x1, y1, x2, y2});
    }

    for(int i = 0; i < 1000; i++) a[i] = -1;
    for(int i = 0; i <= n; i++) par[i] = i;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(rect[i].x1 > rect[j].x2) continue;
            if(rect[i].x2 < rect[j].x1) continue;
            if(rect[i].y1 > rect[j].y2) continue;
            if(rect[i].y2 < rect[j].y1) continue;
            if(rect[i].x1 < rect[j].x1 && rect[i].y1 < rect[j].y1 && rect[i].x2 > rect[j].x2 && rect[i].y2 > rect[j].y2) continue;
            if(rect[i].x1 > rect[j].x1 && rect[i].y1 > rect[j].y1 && rect[i].x2 < rect[j].x2 && rect[i].y2 < rect[j].y2) continue;
            else {
                make_union(i, j);
            }
        } 
    }

    set<int> s;
    for(int i = 0; i <= n; i++) s.insert(find_parent(par[i]));
    cout << s.size()-1;
}