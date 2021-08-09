//2021.08.01
//retry at 2021.08.05

#include<iostream>
#include<stack>

using namespace std;

int main(){
    string str = "";
    string result = "";
    stack<char> s;

    cin >> str;

    for(char ch: str){
        if(ch >= 'A' && ch <= 'Z'){
            result += ch;
        }else if(ch == '('){
            s.push(ch);
        }else if(ch == '*' || ch =='/'){
            while(!s.empty() && (s.top() != '*' || s.top() != '/')){
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }else if(ch == '+' || ch == '-'){
            while(!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }else if(ch == ')'){
            while(!s.empty() && s.top() != '('){
                result += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while(!s.empty()){
        result += s.top();
        s.pop();
    }

    cout << result;
}