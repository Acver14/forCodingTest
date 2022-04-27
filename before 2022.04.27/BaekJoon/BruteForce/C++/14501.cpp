//2021.08.23
#include<iostream>
#include<vector>
using namespace std;

vector<int> T;
vector<int> P;
int n;
int findMax(int a, int b){
    if(a > b) return a;
    return b;
}
int go(int sum, int day){
    if(day == n) return sum;
    else if(day > n) return 0;
    else{
        return findMax(go(sum+P[day], day+T[day]), go(sum, day+1));
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        T.push_back(a);
        cin >> a;
        P.push_back(a);
    }


    cout << go(0, 0);
}