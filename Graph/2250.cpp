//2021.09.15
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int dl[20];
int dr[20];

class Node{
public:
    int left;
    int right;
    int pos;
    int level;
};
vector<int> d[20];

Node tree[10001];
void inorder(int x, int pos, int level){
    if(x == -1) return;
    inorder(tree[x].left, pos-1, level+1);
    tree[x].pos = pos; tree[x].level = level;
    d[level].push_back(pos);
    cout << x << " : " << pos << ' ';
    inorder(tree[x].right, pos+1, level+1);
}


int main(){
    cin >> n;
    int cnt[10001];
    int root;
    for(int i = 0; i < n; i++){
        int p, l, r;
        cin >> p >> l >> r;
        tree[p].left = l;
        tree[p].right = r;
        if(l != -1) cnt[l]++;
        if(r != -1) cnt[r]++;
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0) root = i;
    }

    inorder(root, 0, 0);
    cout << '\n';
    int ans_width = 0;
    int ans_level = 0;

    cout << '\n';
    for(int i = 0; i < 20; i++){
        if(d[i].empty()) break;
        for(int v: d[i]){
            cout << v << ' ';
        }
        cout << '\n';
    }
    cout <<'\n';

    for(int i = 0; i < 20; i++){
        int size = d[i].size();
        if(d[i].empty()) break;
        sort(d[i].begin(), d[i].end());
        int width = d[i][d[i].end()-d[i].begin()] - d[i][0]+1;
        cout << i << ' ' << d[i][d[i].end()-d[i].begin()] << ' ' << d[i][0] << '\n';
        if(ans_width < width) {
            ans_width = width;
            ans_level = i;
        }
    }
    cout << ans_level << ' ' << ans_width;
    return 0;
}