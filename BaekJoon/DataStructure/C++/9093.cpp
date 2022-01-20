//2021.07.27
#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    cin.ignore();

    for(int i = 0; i < t; i++){
        string str;
        getline(cin, str);
        str += '\n';
        stack<char> s;
        for(char ch: str){
            if(ch == ' ' || ch == '\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            }
            else {
                s.push(ch);
                
                }
        }
    }
}