#include<iostream>
#include<queue>
using namespace std;

int t, n, m, _max;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        _max = -1;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            q.push(temp);
            if(_max < temp) _max = temp;
        }

        int cnt = 0;
        while(!q.empty()){
            if(q.front() < _max){
                q.push(q.front());
                q.pop();
                m--;
                if(m == -1) m = q.size()-1;
            }
            else{
                cnt++;
                q.pop();
                _max = -1;
                for(int i = 0 ; i < q.size(); i++){
                    if(_max < q.front()){
                        _max = q.front();
                    }
                    q.push(q.front());
                    q.pop();
                }
                m--;
                if(m == -1) {
                    cout << cnt << '\n';
                    while(!q.empty()) q.pop();
                    break;
                }
            }
        }
    }
}