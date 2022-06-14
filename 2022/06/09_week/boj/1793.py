dp = [0 for _ in range(251)]
dp[0] = 1
dp[1] = 1
dp[2] = 3
idx = 3
while True:
    try:
        n = int(input())
    except:
        break
    if n >= idx:
        for i in range(idx, n+1):
            dp[i] = dp[i-1] + dp[i-2] * 2
        idx = n+1
    print(dp[n])