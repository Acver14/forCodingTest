#include<iostream>
#include<stack>
using namespace std;

stack<char> s;
string par = "";

int main(){
    cin >> par;
    
    int ans = 0;
    int mul = 1;
    for(int i = 0; i < par.length(); i++){
        if(par[i] == '('){
            s.push(par[i]);
            mul *= 2;
        }
        else if(par[i] == ')'){
            if(s.empty() || s.top() != '('){
                cout << 0;
                return 0;
            }else{
                if(par[i-1] == '('){
                    ans += mul;
                }
                s.pop();
                mul /= 2;
            }
        }
        else if(par[i] == '['){
            s.push(par[i]);
            mul *= 3;
        }
        else if(par[i] == ']'){
            if(s.empty() || s.top() != '['){
                cout << 0;
                return 0;
            }else{
                if(par[i-1] == '['){
                    ans += mul;
                }
                s.pop();
                mul /= 3;
            }
        }
    }
    if(s.empty()) cout << ans;
    else cout << 0;
    return 0;
}
