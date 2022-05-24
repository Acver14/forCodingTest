import sys
input = sys.stdin.readline

MOD = 1000000000
n, k = map(int, input().split())

dp = [0 for _ in range(201)]
dp[0] = 1

for _ in range(1, k+1):
    for i in range(1, n+1):
        dp[i] = (dp[i] + dp[i-1]) % MOD

print(dp[n])