#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int value[26] = {};
    string str;
    stack<double> s;

    cin >> n;
    cin >> str;

    for(int i = 0; i < n; i++){
        cin >> value[i];
    }

    for(char ch : str){
        double a, b;
        switch (ch)
        {
        case '+':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(b + a);
            break;
        case '-':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(b - a);
            break;
        case '/':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(b / a);
            break;
        case '*':
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(b * a);
            break;
        default:
            s.push(value[ch - 'A']);
            break;
        }        

    }
        cout << fixed;
        cout.precision(2);
        cout << s.top() << "\n";
}