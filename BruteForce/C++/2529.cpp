//2021.08.23
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool check[10];
char sign[10];
int k;
vector<string> ans;

bool checkSign(char a, char b, char s){
    switch(s){
        case '<':
            if(a < b) return true;
            return false;
        case '>':
            if(a > b) return true;
            return false;
    }
    return false;
}

void go(int index, string num){
    if(index == k+1){
        ans.push_back(num);
        return;
    }
    for(int i = 0; i < 10; i++){
        if(check[i]) continue;
        if(index == 0 || checkSign(num[index-1], i+'0', sign[index-1])){
            check[i] = true;
            go(index+1, num+to_string(i));
            check[i] = false;
        }
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> sign[i];
    }
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n' << *p.first;
}