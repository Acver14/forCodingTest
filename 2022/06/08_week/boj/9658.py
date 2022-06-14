n = int(input())
dp = [False for _ in range(1001)]

dp[1] = dp[3] = True
for i in range(4, n+1):
    if dp[i-1] or dp[i-3] or dp[i-4]:
        continue
    else:
        dp[i] = True
if dp[n]:
    print('CY')
else:
    print('SK')