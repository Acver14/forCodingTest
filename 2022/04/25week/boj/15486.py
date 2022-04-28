import sys
input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
    
dp = [0] * (n+1)

cur = 0
for i in range(n):
    k = i + arr[i][0]
    cur = max(cur, dp[i])
    if k <= n:
        dp[k] = max(dp[k], cur + arr[i][1])
print(max(dp))