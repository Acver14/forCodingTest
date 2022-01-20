//2021.07.28
// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include<iostream>

using namespace std;

class queue{
    int value[10000];
    int start = 0;
    int end = 0;

public:
    int size(){
        return end - start;
    }
    int empty(){
        if(size() == 0) return 1;
        else return 0;
    }
    void push(int x){
        value[end] = x;
        end++;
    }
    int pop(){
        return value[start++];
    }
    int front(){
        if(!empty()) return value[start];
        else return -1;
    }
    int back(){
        if(!empty()) return value[end-1];
        else return -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();
    queue q;
    for(int i = 0; i < n; i ++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(cmd == "pop"){
            if(!q.empty()) cout << q.pop() << '\n';
            else cout << -1 << '\n';
        }
        else if(cmd == "size"){
            cout << q.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << q.empty() << '\n';
        }
        else if(cmd == "front"){
            cout << q.front() << '\n';
        }
        else if(cmd == "back"){
            cout << q.back() << '\n';
        }
    }
}