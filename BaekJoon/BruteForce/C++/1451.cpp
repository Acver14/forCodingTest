//2021.12.22
#include<iostream>
using namespace std;

int n, m;
int a[50][50];
long long ans = 0;
long long sum(int sx, int sy, int ex, int ey){
    long long ret = 0;
    for(int i = sx; i <= ex; i++){
        for(int j = sy; j <= ey; j++){
            ret += a[i][j];
        }
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    long long temp = 0;
    // case 1
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
                temp = sum(0, 0, i, m-1) * sum(i+1, 0, j, m-1) * sum(j+1, 0, n-1, m-1);
                if(temp > ans) ans = temp;
        }
    }
    // case 2
    for(int i = 0; i < m-2; i++){
        for(int j = i+1; j < m-1; j++){
                temp = sum(0, 0, n-1, i) * sum(0, i+1, n-1, j) * sum(0, j+1, n-1, m-1);
                if(temp > ans) ans = temp;
        }
    }
    // case 3
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            temp = sum(0, 0, i, m-1) * sum(i+1, 0, n-1, j) * sum(i+1, j+1, n-1, m-1);
            if(temp > ans) ans = temp;
        }
    }
    // case 4
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            temp = sum(0, 0, i, j) * sum(0, j+1, i, m-1) * sum(i+1, 0, n-1, m-1);
            if(temp > ans) ans = temp;
        }
    }
    // case 5
    for(int i = 0; i < m-1; i++){
        for(int j = 0; j < n-1; j++){
            temp = sum(0, 0, n-1, i) * sum(0, i+1, j, m-1) * sum(j+1, i+1, n-1, m-1);
            if(temp > ans) ans = temp;
        }
    }
    // case 6
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            temp = sum(0, 0, i, j) * sum(i+1, 0, n-1, j) * sum(0, j+1, n-1, m-1);
            if(temp > ans) ans = temp;
        }
    }

    printf("%lld", ans);
}