//2021.07.27
//segment fault 발생 에러 해결 요망
#include<iostream>
#include<stack>

using namespace std;

stack<int> s;

int main(){
    int t;
    cin >> t;
    int n;
    int cnt = 1;
    string result = "";

    s.push(0);

    for(int i = 0; i < t; i++){
        cin >> n;
        while(n > s.top()){
            s.push(cnt++);
            result += "+\n";
        }
        while(n < s.top()){ 
            s.pop();
            result += "-\n";
            if(n != s.top()) {
                result = "NO\n";
                break;
                }
            else {
                s.pop();
                result += "-\n";
                break;
            }
        }
        if(n == s.top()){
            s.pop();
            result += "-\n";
        }
    }

    cout << result;
    return 0;
}