//2021.07.29
#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    stack<char> s;
    char tmp = ' ';
    int numOfLine = 0;
    int ans = 0;

    cin >> str;

    s.push(' ');
    for(char ch: str){
        if(ch == '('){
                s.push(ch);
        }
        else if(ch == ')'){
            if(tmp == ')'){
                s.pop();
                ans++;
            }
            else if(s.top() == '('){
                s.pop();
                ans += s.size() - 1;
            }

        }
        tmp = ch;
    }
    cout << ans;

}