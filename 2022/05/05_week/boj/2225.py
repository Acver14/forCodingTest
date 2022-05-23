import sys
input = sys.stdin.readline

MOD = 1000000000
n, k = map(int, input().split())

dp = [[0] * 201 for _ in range(201)]

dp[1][1] = 1
dp[1][2] = 2
dp[2][1] = 1
dp[2][2] = 3
dp[3][1] = 1
dp[3][2] = 4
dp[3][3] = 1

for i in range(4, n+1):
    dp[i][1] = 2
    dp[i][i] = 2
    for j in range(k+1):
        for l in range(k+1):
            dp[i][j] += dp[l][j-1]

for i in range(n+1):
    for j in range(k+1):
        print(dp[i][j], end=' ')
    print()

print(dp[n][k])