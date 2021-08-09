#include<iostream>
using namespace std;

int main(){
    string str;
    string result = "";
    
    getline(cin, str);

    for(char ch: str){
        int temp = ch + 13;
        if(ch >= 'a' && ch <= 'z'){
            if('z' - temp < 0){
                temp = (char)(temp - 26);
            }
            result += (char)temp;
        }else if(ch >= 'A' && ch <= 'Z'){
            if('Z' - temp < 0){
                temp = (char)(temp - 26);
                
            }
            result += (char)temp;
        }else{
            result += ch;
        }
    }
    cout << result;
}