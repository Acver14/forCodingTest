//2021.08.18
#include<iostream>
using namespace std;

int M, N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t, x, y;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> M >> N >> x >> y;
        int year = 0;
        if(M < N) {
            year = x;
            y %= N;
            for(; year <= M*N; year+=M){
                if(year%N == y){
                    cout << year << '\n';
                    break;
                }
            }
        }
        else {
            year = y;
            x %= M;
            for(; year <= M*N; year+=N){
                if(year%M == x){
                    cout << year << '\n';
                    break;
                }
            }
        }
        if(year > M*N) cout << -1 << '\n';
    }
}