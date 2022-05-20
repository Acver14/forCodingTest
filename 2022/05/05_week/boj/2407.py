import sys
input = sys.stdin.readline

n, m = map(int, input().split())

dp = [[0] * (101) for _ in range(101)]

dp[1][0] = 1
dp[1][1] = 1
for i in range(2, n+1):
    for j in range(n+1):
        if j == 0 or j == m:
            dp[i][j] = 1
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

print(dp[n][m])