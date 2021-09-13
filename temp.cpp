#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<char> str;
bool prime(int a){
    int i = 2;
    if (a == 1){
        return true;
    }
    while(i*i <= a){
        if(a % i == 0){
            return true;
        }
        i++;
    }
    return false;
}

void change(int n, int jin){
    if(n != 0){
        change(n/jin, jin);
        str.push_back(n % jin);
    }else{
        return;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int answer = 0;
    change(n, k);
    string st = "";
    for(int i : str){
        cout << i << '\n';
    }
    int string_to_int;
    for(int i = 0; i < str.size(); i++){
        cout << " st : " << st << " " << (st != "") << '\n';
        if(str[i] == '0' && st != ""){
            string_to_int = stoi(st);
            if(prime(string_to_int) == false){
                answer ++;
            }
            st = "";
        }else{
            st += str[i];
        }
    }
    string_to_int = stoi(st);
    if(prime(string_to_int) == false){
        answer ++;
    }
    cout << answer;
    return 0;
}