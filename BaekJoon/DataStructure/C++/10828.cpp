//2021.07.27
#include<iostream>
using namespace std;

class  stack{
    int value[10001];
    int size = 0;

    public:
    bool isEmpty(){
        if(size == 0){
            return true;
        }else {
            return false;
        }
    }

    void push(int x){
        value[size] = x;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout << -1 << '\n';
        }else{
            cout << value[size-1] << '\n';
            size--;
        }
    }

    void getSize(){
        cout << size << '\n';
    }

    void top(){
        if(isEmpty()){
            cout << -1 << '\n';
        }else{
            cout << value[size-1] << '\n';
        }
    }
};


int main(){
    int n;
    stack s;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        if(command == "push"){
            int x;
            cin >> x;
            s.push(x);
        }else if(command == "pop"){
            s.pop();
        }else if(command == "size"){
            s.getSize();
        }else if(command == "empty"){
            if(s.isEmpty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(command == "top"){
            s.top();
        }else{}
        

    }
    return 0;
}