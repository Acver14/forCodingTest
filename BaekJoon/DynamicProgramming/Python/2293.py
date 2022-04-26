import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coins = []
for _ in range(n):
    coins.append(int(input()))
    
dp = [0] * (k+1)
dp[0] = 1
for i in coins:
    for j in range(k+1):
        if j >= i:
            dp[j] += dp[j-i]
print(dp[k])