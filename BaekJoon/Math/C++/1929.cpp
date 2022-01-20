//2021.08.02
#include<iostream>
using namespace std;

bool check[1000001];

int main(){
    int start, end;

    cin >> start >> end;
    check[0] = check[1] = true;
    for(int i = 2; i <= end; i++){
        if(check[i] == false) {
            for(int j = i*2; j <=end; j+=i){
                check[j] = true;
            }
        }
    }

    for(int i = start; i <= end; i++){
        if(!check[i]) cout << i << '\n';
    }
}