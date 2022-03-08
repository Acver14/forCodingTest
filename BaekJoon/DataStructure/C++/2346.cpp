#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    deque<pair<int, int> > dq;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        dq.push_back(make_pair(temp, i));
    }

    // cout << dq.size() << '\n';
    while(true){
        cout << dq.front().second+1 << ' ';
        int cnt = dq.front().first;
        dq.pop_front();
        if(dq.empty()) break;
        if(cnt > 0){
            for(int i = 0; i < cnt-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            for(int i = cnt; i < 0; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

