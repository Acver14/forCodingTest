//2021.09.14
#include<iostream>
#include<vector>
using namespace std;

int n;

class Node{
public:
    int left;
    int right;
};

Node tree[50];

void preorder(int x){
    if(x == -1) return;
    cout << char(x+'A');
    preorder(tree[x].left);
    preorder(tree[x].right);
}

void inorder(int x){
    if(x == -1) return;
    inorder(tree[x].left);
    cout << char(x+'A');
    inorder(tree[x].right);
}

void postorder(int x){
    if(x == -1) return;
    postorder(tree[x].left);
    postorder(tree[x].right);
    cout << char(x+'A');
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        char p, c1, c2;
        cin >> p >> c1 >> c2;
        p = p - 'A';
        if(c1 == '.'){
            tree[p].left = -1;
        }else{
            tree[p].left = c1 - 'A';
        }
        if(c2 == '.'){
            tree[p].right = -1;
        }else{
            tree[p].right = c2 - 'A';
        }
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;
}