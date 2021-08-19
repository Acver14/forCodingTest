// //2021.08.19
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<string>
// using namespace std;

// int c[10];
// int a[10];
// int num[10];
// string str = "";
// vector<string> v;

// void printNum(int index, int n, int m){
//     if(index == m){
//         for(int i = 0; i < m; i++){
//             str += to_string(num[a[i]]);
//             if(i != m-1) str += ' ';
//         }
//         v.push_back(str);
//         str = "";
//         return;
//     }
//     for(int i = 0; i < n; i++){
//         if(c[i]) continue;
//         c[i] = true;
//         a[index] = i;
//         printNum(index+1, n, m);
//         c[i] = false;
//     }
// }

// int main(){
//     int n, m;
//     cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         cin >> num[i];
//     }
//     sort(num, num+n);
//     printNum(0, n, m);

//     //sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());

//     for(string &i: v){
//         cout << i << '\n';
//     }
// }

// // 위 코드에서 오답을 뱉는 경우 -> 3 2 10 2 10 why? string 형식으로 바꿔 한번에 출력하기 때문에 사전식 정렬이 되지 않는다(즉 10이 2 보다 앞서 위치하게 된다.)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[10];
int num[10];
int c[10];
vector<vector<int>> d;
void go(int index, int n, int m) {
    if (index == m) {
        vector<int> temp;
        for (int i=0; i<m; i++) {
            temp.push_back(num[a[i]]);
        }
        d.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++) {
        if (c[i]) continue;
        c[i] = true;
        a[index] = i;
        go(index+1, n, m);
        c[i] = false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num,num+n);
    go(0,n,m);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    for (auto &v : d) {
        for (int i=0; i<m; i++) {
            cout << v[i];
            if (i != m-1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}