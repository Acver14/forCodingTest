//2021.08.25
#include<iostream>
using namespace std;

// int S[21];

// void add(int x){
//     S[x] = 1;
// }
// void remove(int x){
//     S[x] = 0;
// }
// void check(int x){
//     cout << S[x] << '\n';
// }
// void toggle(int x){
//     if(S[x]) S[x] = 0;
//     else S[x] = 1;
// }
// void all(){
//     fill_n(S, 21, 1);
// }
// void empty(){
//     fill_n(S,21,0);
// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     fill_n(S, 21, 0);
//     string cmd;
//     int n, m;
//     cin >> m;
//     for(int i = 0; i < m; i++){
//         cin >> cmd;
//         if(cmd == "add"){
//             cin >> n;
//             add(n);
//         }
//         else if(cmd == "remove"){
//             cin >> n;
//             remove(n);
//         }
//         else if(cmd == "check"){
//             cin >> n;
//             check(n);
//         }
//         else if(cmd == "toggle"){
//             cin >> n;
//             toggle(n);
//         }
//         else if(cmd == "all"){
//             all();
//         }
//         else if(cmd == "empty"){
//             empty();
//         }
//     }
// }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s=0, m, n;
    string cmd;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >> n;
            s = s|(1<<n);
        }else if(cmd == "remove"){
            cin >> n;
            s = s&~(1<<n);
        }else if(cmd == "toggle"){
            cin >> n;
            s = s^(1<<n);
        }else if(cmd == "check"){
            cin >> n;
            cout << (bool)(s&(1<<n)) << '\n';
        }else if(cmd == "all"){
            s = 0;
            s = ~s;
        }else if(cmd == "empty"){
            s = 0;
        }
    }
}