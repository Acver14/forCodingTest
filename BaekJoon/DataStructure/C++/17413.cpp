//2021.07.29
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> s;
    string str = "";
    string result;
    bool flag = false;

    getline(cin, str);

    for(char ch: str){
        if(ch == '<') {
            while(!s.empty()){
                result += s.top();
                s.pop();
            }
            result += ch;
            flag = true;
            continue;
        }
        if(ch == ' '){
            while(!s.empty()){
                result += s.top();
                // cout << result << '\n';
                s.pop();
            }
            result += ch;
            continue;
        }
        if(ch == '>') {
            flag = false;
            result += ch;
            continue;
        }
        if(flag){
            result += ch;
            continue;
        }
        else{
            s.push(ch);
            continue;
            cout << "push : "<< ch << '\n';
        }
    }

    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    cout << result;
}