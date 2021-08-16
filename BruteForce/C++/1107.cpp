//2021.08.16
#include <iostream>
#include <vector>
using namespace std;

long long goToN(int n, int broken[10])
{
    int N = n;
    long long click = 0;
    int ret = 100;
    long long cnt = -1;
    while (N != 0)
    {
        cnt++;
        int a = N % 10;
        N /= 10;
        if (!broken[a])
        {
            click++;
            int temp = 1;
            for (int j = 0; j < cnt; j++)
            {
                temp *= 10;
            }
            ret -= (ret%temp)/temp*temp;
            ret += a * temp;
            continue;
        }
        else
        {
            for (int j = 1;; j++)
            {
                if (!broken[a + j])
                {
                    int temp = 1;
                    for (int j = 0; j < cnt; j++)
                    {
                        temp *= 10;
                    }
                    ret -= (ret%temp)/temp*temp;
                    cout << temp << '\n';
                    cout << (ret%temp)*temp << '\n';
                    ret += (a + j) * temp;
                    cout << ret << '\n';
                    cout << "--------'\n";

                    click++;
                    break;
                }
                else if (!broken[a - j])
                {
                    int temp = 1;
                    for (int j = 0; j < cnt; j++)
                    {
                        temp *= 10;
                    }
                    ret -= (ret%temp)/temp*temp;
                    ret += (a - j) * temp;
                    click++;
                    break;
                }
            }
        }
    }
    if (ret > n)
        click += ret - n;
    else
        click += n - ret;
    return click;
}

int main()
{
    int channel = 100;
    int n;
    int ans = 0;
    cin >> n;
    int m;
    cin >> m;
    int broken[10];
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        broken[input] = true;
    }
    if (n-channel == 0)
    {
        cout << ans;
        return 0;
    }else if(n-channel < 4){
        cout << n-channel;
        return 0;
    }
    cout << goToN(n, broken);
    return 0;
}