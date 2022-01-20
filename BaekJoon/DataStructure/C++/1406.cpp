//2021.07.28
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> left;
    stack<char> right;

    string  str;
    int numOfCmd;
    cin >> str;
    for(char ch: str){
        left.push(ch);
    }
    cin >> numOfCmd;

    for(int i = 0; i < numOfCmd; i++){
        char cmd;
        cin >> cmd;
        if(cmd == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(cmd == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if(cmd == 'B'){
            if(!left.empty()){
                left.pop();
            }
        }
        else if(cmd == 'P'){
            char p;
            cin >> p;
            left.push(p);
        }
    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }


}