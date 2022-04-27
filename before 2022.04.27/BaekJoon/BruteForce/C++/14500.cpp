//2021.08.17
#include<iostream>
using namespace std;

int main(){
    int n, m;
    int a[501][501];
    int result = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n-3; i++){
        for(int j = 0; j < m; j++){
            int sum = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-3; j++){
            int sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            int sum = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-2; j++){
            int sum = a[i][j] + a[i+1][j] + a[i][j+1] + a[i][j+2];
            if(sum > result) result = sum;
            sum = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
            if(sum > result) result = sum;
            sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
            if(sum > result) result = sum;
            sum = a[i+1][j] + a[i+1][j+1] + a[i+1][j+2] + a[i][j+2];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m-1; j++){
            int sum = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1];
            if(sum > result) result = sum;
            sum = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
            if(sum > result) result = sum;
            sum = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
            if(sum > result) result = sum;
            sum = a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + a[i+2][j];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m-1; j++){
            int sum = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1];
            if(sum > result) result = sum;
            sum = a[i][j+1] + a[i+1][j+1] + a[i+1][j] + a[i+2][j];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-2; j++){
            int sum = a[i+1][j] + a[i+1][j+1] + a[i][j+1] + a[i][j+2];
            if(sum > result) result = sum;
            sum = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
            if(sum > result) result = sum;
        }
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-2; j++){
            int sum = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1];
            if(sum > result) result = sum;
            sum = a[i+1][j] + a[i+1][j+1] + a[i+1][j+2] + a[i][j+1];
            if(sum > result) result = sum;
        }
    }

    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m-1; j++){
            int sum = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+1][j+1];
            if(sum > result) result = sum;
            sum = a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + a[i+1][j];
            if(sum > result) result = sum;
        }
    }
    cout << result;
}