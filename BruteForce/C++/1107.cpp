//2021.08.16
//retry at 2021.07.17
#include<iostream>
#include<cmath>
using namespace std;

bool broken[10];
int channel = 100;
int target;

int goToTarget(int n){
    if(n == 0){
        if(broken[0]) return 0;
        else return 1;
    }
    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> target;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        broken[a] = true;
    }
    int result;

    result = abs(channel-target);
    for(int i = 0; i <= 1000000; i++){
        int c = i;
        int click = goToTarget(c);
        if(click > 0){
            int press = abs(target-c);
            if(result > press + click){
                result = press + click;
            }
        }
    }

    cout << result;
}