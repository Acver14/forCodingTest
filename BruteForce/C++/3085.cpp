//2021.08.16
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char> > v(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    int ansTemp = 1;

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         for(int k = i; k < n-1; k++){
    //             if(v[k][j] == v[k+1][j]){
    //                 ansTemp++;
    //             }else {
    //                 if(ans < ansTemp) ans = ansTemp;
    //                 ansTemp = 1;
    //                 break;
    //             }
    //         }
    //         for(int x = j; x < n-1; x++){
    //             if(v[i][x] == v[i][x+1]){
    //                 ansTemp++;
    //             }else {
    //                 if(ans < ansTemp) ans = ansTemp;
    //                 ansTemp = 1;
    //                 break;
    //             }
    //         }
    //     }
    // }
    for (int l = 0; l < n; l++)
    {
        for (int m = 0; m < n - 1; m++)
        {
            swap(v[m][l], v[m + 1][l]);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = i; k < n - 1; k++)
                    {
                        if (v[k][j] == v[k + 1][j])
                        {
                            ansTemp++;
                        }
                        else
                        {
                            if (ans < ansTemp)
                                ans = ansTemp;
                            ansTemp = 1;
                            break;
                        }
                    }
                    if (ans < ansTemp)
                        ans = ansTemp;
                    ansTemp = 1;
                    for (int x = j; x < n - 1; x++)
                    {
                        if (v[i][x] == v[i][x + 1])
                        {
                            ansTemp++;
                        }
                        else
                        {
                            if (ans < ansTemp)
                                ans = ansTemp;
                            ansTemp = 0;
                            break;
                        }
                    }
                    if (ans < ansTemp)
                        ans = ansTemp;
                    ansTemp = 1;
                }
            }
            swap(v[m][l], v[m + 1][l]);
        }
    }
    for (int l = 0; l < n - 1; l++)
    {
        for (int m = 0; m < n; m++)
        {
            swap(v[m][l], v[m][l + 1]);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = i; k < n - 1; k++)
                    {
                        if (v[k][j] == v[k + 1][j])
                        {
                            ansTemp++;
                            if (j == 0)
                            {
                            }
                        }
                        else
                        {
                            if (ans < ansTemp)
                                ans = ansTemp;
                            ansTemp = 1;
                            break;
                        }
                    }
                    if (ans < ansTemp)
                        ans = ansTemp;
                    ansTemp = 1;
                    for (int x = j; x < n - 1; x++)
                    {
                        if (v[i][x] == v[i][x + 1])
                        {
                            ansTemp++;
                        }
                        else
                        {
                            if (ans < ansTemp)
                                ans = ansTemp;
                            ansTemp = 1;
                            break;
                        }
                    }
                    if (ans < ansTemp)
                        ans = ansTemp;
                    ansTemp = 1;
                }
            }
            swap(v[m][l], v[m][l + 1]);
        }
    }
    cout << ans;
}