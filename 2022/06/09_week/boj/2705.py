t = int(input())

dp = [1 for _ in range(1001)]
dp[0] = 0
for i in range(1, 1001):
    for j in range(i):
        if (i - j) & 1: continue
        dp[i] += dp[i - j >> 1]

for i in range(t):
    n = int(input())
    print(dp[n])