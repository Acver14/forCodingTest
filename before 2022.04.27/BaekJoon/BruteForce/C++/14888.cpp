//2021.09.17
#include<iostream>
using namespace std;

int n;
int num[11];
int oper[4];
int minAns = 1000000001;
int maxAns = -1000000001;

void go(int result, int idx){
    if(idx == n){
        if(result > maxAns) maxAns = result;
        if(result < minAns) minAns = result;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(oper[i] > 0){
            oper[i]--;
            switch(i){
                case 0:
                    go(result + num[idx], idx+1);
                    break;
                case 1:
                    go(result - num[idx], idx+1);
                    break;
                case 2:
                    go(result * num[idx], idx+1);
                    break;
                case 3:
                    go(result / num[idx], idx+1);
                    break;
            }
            oper[i]++;
        }
    }
    return;
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> oper[i];
    }

    go(num[0], 1);
    cout << maxAns << '\n' << minAns << '\n';
}