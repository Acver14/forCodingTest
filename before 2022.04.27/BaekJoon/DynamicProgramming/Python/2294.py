import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
    
INF = 100000
dp = [INF] * (k+1)

dp[0] = 0
for j in range(k+1):
    for i in coins:
        if j >= i:
            dp[j] = min(dp[j-i]+1, dp[j])
if dp[k] == INF:
    print(-1)
else:
    print(dp[k])