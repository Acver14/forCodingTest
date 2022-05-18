import sys
input = sys.stdin.readline

t = int(input())
MOD = 1000000007

dp = [0 for _ in range(5001)]
dp[0] = 1
dp[2] = 1

for i in range(3, 5001):
    for j in range(2, i+1):
        dp[i] += dp[j-2] * dp[i-j]
    dp[i] %= MOD

for _ in range(t):
    n = int(input())
    
    print(dp[n])