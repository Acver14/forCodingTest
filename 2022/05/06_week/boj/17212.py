n = int(input())

INF = 100001
dp = [INF for _ in range(INF)]
dp[0] = 0
dp[1] = 1
dp[2] = 1
dp[5] = 1
dp[7] = 1

for i in range(3, n+1):
    if dp[i] == INF:
        dp[i] = min(dp[i-1], dp[i-2], dp[i-5], dp[i-7]) + 1

print(dp[n])