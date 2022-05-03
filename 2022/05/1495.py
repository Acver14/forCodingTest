import sys
input = sys.stdin.readline

n, s, m = map(int, input().split())
v = list(map(int, input().split()))

dp = [[-1] * (m+1) for _ in range(n)]

if s+v[0] <= m:
    dp[0][s+v[0]] = s+v[0]
if s-v[0] >= 0:
    dp[0][s-v[0]] = s-v[0]
for i in range(1, n):
    for j in range(m+1):
        if dp[i-1][j] != -1:
            if j+v[i] <= m:
                dp[i][j+v[i]] = j+v[i]
            if j-v[i] >= 0:
                dp[i][j-v[i]] = j-v[i]
for i in range(n):
    print(dp[i])
print(max(dp[n-1]))