//2022.01.13
#include<iostream>
#include<vector>
using namespace std;

int n, len;
int ans = 0;
vector<int> prime;

void findPrime(){
    int a[4000001] = {0, };

	for (int i = 2; i <= n; i++)
		for (int j = 2; i * j <= n; j++)
			a[i * j] = 1;

	for (int i = 2; i <= n; i++)
		if (!a[i]) prime.push_back(i);
}

void twoPoint(){
    int low = 0, high = 0;
    int sum = prime[0];

    while (low <= high && high < len)
    {
        if (sum < n)
            sum += prime[++high];
        else if (sum == n)
        {
            ans++;
            sum += prime[++high];
        }
        else if (sum > n)
        {
            sum -= prime[low++];
        }
    }
}

int main(){
    cin >> n;
    findPrime();
    len = prime.size();
    if(len == 0){
        cout << 0;
        return 0;
    }
    twoPoint();
    cout << ans;
}