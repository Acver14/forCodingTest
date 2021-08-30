//2021.08.30
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[2000][2000];
vector<int> v[2000];
vector< pair<int,int> > l;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;
        a[first][second] = 1;
        a[second][first] = 1;
        v[first].push_back(second);
        v[second].push_back(first);
        l.push_back({first, second});
        l.push_back({second, first});
    }
    m *= 2;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int A = l[i].first;
            int B = l[i].second;
            int C = l[j].first;
            int D = l[j].second;
            if(A == B || A == C || A == D || B == C || B == D || C == D) continue;
            if(!a[B][C]) continue;
            for(int E : v[D]){
                if(A == E || B == E || C == E || D == E) continue;
            }
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;

}