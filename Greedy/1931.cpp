//2021.12.15
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting{
    long long start, end;
}typedef meeting;

int n;
vector<meeting> v;

bool comp(meeting a, meeting b){
    if(a.end == b.end) {
        if(a.start < b.start) return true;
    }
    return a.end < b.end;
}

int greedy(){
    int now = 0;
    int ans = 0;
    for(meeting i: v){
        if(now <= i.start){
            now = i.end;
            ans++;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        long long s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), comp);

    cout << greedy();
}