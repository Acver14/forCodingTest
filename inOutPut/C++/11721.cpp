//2021.07.20
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);

    while(true){
        if(str.length() > 9) cout << str.substr(0, 10) << endl;
        else {
            cout << str.substr(0, str.length()) << endl;
            break;
            }
        str.erase(0, 10);
    }
    return 0;
}