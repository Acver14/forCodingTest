//2021.09.24
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> w;
vector<int> v;
int ans = 0;
int tempAns = 0;

void go(){
    int size = w.size();
    if(size == 2){
        if(ans < tempAns) ans = tempAns;
        return;
    }
    for(int i = 1; i < size-1; i++){
        int temp = w[i];
        tempAns += w[i-1] * w[i+1];
        w.erase(w.begin()+i);
        go();
        w.insert(w.begin()+i, temp);
        tempAns -= w[i-1] * w[i+1];
    }
}

int main(){
    cin >> n;
    w.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    v = w;
    go();
    cout << ans;
}