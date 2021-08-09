//2021.07.28
// push_front X: 정수 X를 덱의 앞에 넣는다.
// push_back X: 정수 X를 덱의 뒤에 넣는다.
// pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 덱에 들어있는 정수의 개수를 출력한다.
// empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
// front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include<iostream>
#include<string>
using namespace std;

#define SIZE_OF_DECK 10000

class deck{
    int value[SIZE_OF_DECK];
    int front = 0;
    int back = 0;

public:
    int size(){
        if(front > back){
            return SIZE_OF_DECK + back - front;
        }
        return back - front;
    }
    int empty(){
        if(size() == 0) return 1;
        else return 0;
    }
    void push_front(int x){
        if(front == 0){
            front = SIZE_OF_DECK-1;
        }else{
            front--;
        }
        value[front] = x;
    }
    void push_back(int x){
        value[back] = x;
        if(back == SIZE_OF_DECK-1) back = 0;
        else back++;
    }
    int pop_front(){
        int ret = value[front];;
        if(empty()){
            return -1;
        }
        else {
            if(front==SIZE_OF_DECK-1){
                front = 0;
            }
            else{
                front++;
            }
            return ret;
        }
    }
    int pop_back(){
        if(empty()){
            return -1;
        }
        else{
            if(back == 0){
                back = SIZE_OF_DECK - 1;
                return value[back];
            }
            else{
                back--;
                return value[back];
            }
        }
    }
    int _front(){
        if(empty()){
            return -1;
        }
        else {
            return value[front];
        }
    }
    int _back(){
        if(empty()){
            return -1;
        }
        else{
            if(back == 0){
                return value[SIZE_OF_DECK - 1];
            }
            else{
                return value[back-1];
            }
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string result = "";
    int n;
    cin >> n;
    cin.ignore();
    deck d;
    for(int i = 0; i < n; i ++){
        string cmd;
        cin >> cmd;
        if(cmd == "push_back"){
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if(cmd == "push_front"){
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if(cmd == "pop_back"){
            //cout << d.pop_back() << '\n';
            result += to_string(d.pop_back()) + '\n';
        }
        else if(cmd == "pop_front"){
            // cout << d.pop_front() << '\n';
            result += to_string(d.pop_front()) + '\n';
        }
        else if(cmd == "size"){
            // cout << d.size() << '\n';
            result += to_string(d.size()) + '\n';
        }
        else if(cmd == "empty"){
            // cout << d.empty() << '\n';
            result += to_string(d.empty()) + '\n';
        }
        else if(cmd == "front"){
            // cout << d._front() << '\n';
            result += to_string(d._front()) + '\n';
        }
        else if(cmd == "back"){
            // cout << d._back() << '\n';
            result += to_string(d._back()) + '\n';
        }

    }
        cout << result;
}