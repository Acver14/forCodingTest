import sys
input = sys.stdin.readline

n = int(input())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

dp = [[0]*n for _ in range(n)]

dp[arr[0][0]][0] = 1
dp[0][arr[0][0]] = 1
for i in range(n):
    for j in range(n):
        mov = arr[i][j]
        if mov == 0:
            continue
        if i+mov < n:
            dp[i+mov][j] += dp[i][j]
        if j+mov < n:
            dp[i][j+mov] += dp[i][j]

print(dp[n-1][n-1])