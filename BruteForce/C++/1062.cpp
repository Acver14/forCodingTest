//2021.09.30
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, k;
int alpNum = 5;
int alp = 0;
int word[50];
int check = 0;
int ans = 0;
int vlen;
vector<int> v;
void go(int idx){
    if(k==alpNum || vlen==alpNum-5){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(word[i]&(~check)) continue;
            else cnt++;
        }
        if(cnt > ans) ans = cnt;
        return;
    }
    for(int i = idx; i < vlen; i++){
            check += v[i];
            alpNum++;
            go(i+1);
            check -= v[i];
            alpNum--;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    if(k < 5){
        cout << 0;
        return 0;
    }
    else if(k == 26){
        cout << n << '\n';
        return 0;
    }

    check += ((1<<('a'-'a')) + (1<<('n'-'a')) + (1<<('t'-'a')) + (1<<('i'-'a')) + (1<<('c'-'a')));
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        temp = temp.substr(4, temp.length());
        for(int i = 0; i < 4; i++){
            temp.pop_back();
        }
        for(char c: temp){
            int x = (1<<(c-'a'));
            if(!(word[i]&x)) word[i] += x;
            if(!(alp&x) && !(check&x)) {
                v.emplace_back(x);
                alp += x;
            }
        }
    }
    vlen = v.size();
    go(0);
    cout << ans;
    return 0;
}