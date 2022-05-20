import sys
from collections import deque
input = sys.stdin.readline

n = int(input())

arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

INF = 2**31-1
dp = [[0] * (n) for _ in range(n)]

for i in range(1, n):
    for j in range(n-i):
        x = j+i
        dp[j][x] = INF
        for k in range(j, x):
            dp[j][x] = min(dp[j][x], dp[j][k] + dp[k + 1][x] + arr[j][0] * arr[k][1] * arr[x][1])