#include<iostream>
using namespace std;

int main(){
    int num, smallAlpha, largeAlpha, space;

    num = smallAlpha = largeAlpha = space = 0;

    string str;
    
    while(getline(cin, str)){
        for(char ch: str){
            if(ch >= 'a' && ch <= 'z'){
                smallAlpha++;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                largeAlpha++;
            }
            else if(ch >= '0' && ch <= '9'){
                num++;
            }
            else if(ch == ' '){
                space++;
            }
        }
        cout << smallAlpha << ' ' << largeAlpha << ' ' << num << ' ' << space << '\n';
        
        num = smallAlpha = largeAlpha = space = 0;
    }
}