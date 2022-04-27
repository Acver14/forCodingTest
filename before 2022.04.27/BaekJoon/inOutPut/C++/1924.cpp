//2021.07.21
#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int year = 2007;

    for(int i = 1; i < x; i++){
        switch (i)
        {
        case 2:
            y += 28;
            break;
        case 1:
            y += 31;
            break;
        case 3:
            y += 31;
            break;
        case 5:
            y += 31;
            break;
        case 7:
            y += 31;
            break;
        case 8:
            y += 31;
            break;
        case 10:
            y += 31;
            break;
        case 12:
            y += 31;
            break;
        default:
            y += 30;
            break;
        }
    }
    switch (y%7)
        {
        case 0:
            cout << "SUN";
            break;
        case 1:
            cout << "MON";
            break;
        case 2:
            cout << "TUE";
            break;
        case 3:
            cout << "WED";
            break;
        case 4:
            cout << "THU";
            break;
        case 5:
            cout << "FRI";
            break;
        default:
            cout << "SAT";
        }
    return 0;
}