import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

dp = [[0] * m for _ in range(n)]

dp[0][0] = m - arr[0]

idx = 0
for i in range(1, n):
    if dp[idx][i-1] != 0 and dp[idx][i-1] + arr[i] + 1 <= m:
        dp[idx][i] = dp[idx][i-1] + arr[i] + 1
    if dp[idx][i-1] == 0 and dp[idx][i-1] + arr[i] <= m:
        dp[idx][i] = dp[idx][i-1] + arr[i]
    if dp[idx+1][i-1] != 0 and dp[idx+1][i-1] + arr[i] + 1 <= m:
        dp[idx+1][i] = dp[idx+1][i-1] + arr[i] + 1
    if dp[idx+1][i-1] == 0 and dp[idx+1][i-1] + arr[i] <= m:
        dp[idx+1][i] = dp[idx+1][i-1] + arr[i]
    