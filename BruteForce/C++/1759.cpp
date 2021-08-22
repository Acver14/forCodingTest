//2021.08.22
#include<iostream>
#include<algorithm>
using namespace std;

bool check(string password, int len){
    int ja = 0;
    int mo = 0;
    for(int i = 0; i < len; i++){
        if(password[i] == 'a' || password[i] == 'e' || password[i] == 'o' || password[i] == 'i' || password[i] == 'u'){
            mo++;
        }else{
            ja++;
        }
    }
    if(mo > 0 && ja > 1) return true;
    else return false;
}
bool checkInd[15];
void go(char* alpha, string password, int c, int l, int start){
    if(password.length() == l){
        if(check(password, l)) cout << password << '\n';
        return;
    }
    else if(password.length() > l) return;
    else{
        if(start >= c) return;
            go(alpha, password + alpha[start], c, l, start+1);
            go(alpha, password, c, l, start+1);
        
    }
}


int main(){
    int l, c;
    char alpha[15];
    cin >> l >> c;

    for(int i = 0; i < c; i++){
        cin >> alpha[i];
    }
    sort(alpha, alpha+c);

    go(alpha, "", c, l, 0);
}