import sys

input = sys.stdin.readline

n = int(input())

dp = [False for _ in range(1001)]
dp[1] = True
dp[3] = True
dp[4] = True
dp[5] = True
dp[6] = True

for i in range(7, n+1):
    if not dp[i-1] or not dp[i-3] or not dp[i-4]:
        dp[i] = True
        
if dp[n]:
    print('SK')
else:
    print('CY')