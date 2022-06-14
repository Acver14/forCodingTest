n = int(input())
dp = [[0] * 3 for _ in range(10)]
dp[2][1] = 1
dp[2][2] = 1
dp[3][0] = 2
dp[3][1] = 2
dp[3][2] = 2

for i in range(4, n+1):
    dp[i][0] = dp[i-1][1] + dp[i-1][2]
    dp[i][1] = sum(dp[i-2]) + sum(dp[i-3])
    dp[i][2] = dp[i][1]
print(sum(dp[n]))