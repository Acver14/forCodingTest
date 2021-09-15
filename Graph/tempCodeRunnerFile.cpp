//2021.09.15
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

class Node{
public:
    int left;
    int right;
};

vector<Node> tree;
vector<int> node[10001];
int col_cnt = 0;
vector<int> col;
int level = 0;

void inorder(int x, int _level){
    if(x == -1) return;
    inorder(tree[x].left, _level+1);
    col[x] = ++col_cnt;
    node[_level].push_back(x);
    inorder(tree[x].right, _level+1);
    if(level < _level) level = _level;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    vector<int> cnt(n+1);
    tree.resize(n+1);
    col.resize(n+1);
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

    inorder(root, 1);
    int ans = 0;
    int idx = 1;
    for(int i = 0; i < level; i++){
        int size = node[i].size();
        for(int j = 0; j < size; j++){
            for(int k = 1; k < size; k++){
                int comp = abs(col[node[i][j]] - col[node[i][k]]) + 1;
                if(ans < comp) {
                    ans = comp;
                    idx = i;
                }
            }
        }
    }
    cout << idx << ' ' << ans;

    return 0;
}