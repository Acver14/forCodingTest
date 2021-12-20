//2021.12.20
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int r, c, minn, minn_c, minn_r;
int a[1001][1001];

void ifROdd(){
    for(int i=0;i<r/2;i++){
        for(int j=1;j<c;j++){
            cout << 'R';
        }
        
        cout << 'D';
        
        for(int j=1;j<c;j++){
            cout << 'L';
        }
        
        cout << 'D';
    }
    
    for(int j=1;j<c;j++){
        cout << 'R';
    }
    
    cout << '\n';
}

void ifCOdd(){
    for(int i=0;i<c/2;i++){
        for(int j=1;j<r;j++){
            cout << 'D';
        }
        
        cout << 'R';
        
        for(int j=1;j<r;j++){
            cout << 'U';
        }
        
        cout << 'R';
    }
    
    for(int j=1;j<r;j++){
        cout << 'D';
    }
    
    cout << '\n';
}


void ifEven(){
    string ans = "";
    string ans2 = "";
    
    int x1 = 0;
    int x2 = r-1;
    int y1 = 0;
    int y2 = c-1;
    
    while(x1/2 < minn_r/2){
        for(int j=0;j<c-1;j++){
            ans.push_back('R');
        }
        ans.push_back('D');
        for(int j=0;j<c-1;j++){
            ans.push_back('L');
        }
        ans.push_back('D');
        
        x1 += 2;
    }
    
    while(x2/2 > minn_r/2){
        for(int j=0;j<c-1;j++){
            ans2.push_back('R');
        }
        ans2.push_back('D');
        for(int j=0;j<c-1;j++){
            ans2.push_back('L');
        }
        ans2.push_back('D');
        
        x2 -= 2;
    }
    
    
    
    while(y1/2 < minn_c/2){
        ans.push_back('D');
        ans.push_back('R');
        ans.push_back('U');
        ans.push_back('R');
        y1 += 2;
    }
    
    while(y2/2 > minn_c/2){
        ans2.push_back('D');
        ans2.push_back('R');
        ans2.push_back('U');
        ans2.push_back('R');
        y2 -= 2;
    }
    
    if(minn_c == y1){
        ans.push_back('R');
        ans.push_back('D');
    }
    else{
        ans.push_back('D');
        ans.push_back('R');
    }
    
    reverse(ans2.begin(), ans2.end());
    
    ans += ans2;
    
    cout << ans << '\n';
}



int main() {
	ios_base :: sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    minn = 1000000;
    
    cin >> r >> c;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
            
            if((i+j)%2==1 && a[i][j] < minn){
                minn_r = i;
                minn_c = j;
                minn = a[i][j];
            }
        }
    }
    
    if(r%2 == 1) ifROdd();
    else if(c%2 == 1) ifCOdd();
    else ifEven();
    
	return 0;
}