import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n = int(input())
d = [[0] * (n+1) for _ in range(n+1)]
m = [[0 for _ in range(n+1)]]
for i in range(n):
    m.append([0] + list(map(int, input().split())))

cnt = 0

dp = [[-1] * (n+1) for _ in range(n+1)]
d = [[0] * (n+1) for _ in range(n+1)]
MOD = 1000000007
def matrix_path_rec(m, i, j):
    if i == 0 or j == 0:
        d[i][j] += 1
        d[i][j] %= MOD
        return 0
    else:
        if dp[i-1][j] == -1:
            dp[i-1][j] = matrix_path_rec(m, i-1, j)
        if dp[i][j-1] == -1:
            dp[i][j-1] = matrix_path_rec(m, i, j-1)
        d[i][j] += (d[i][j-1] + d[i-1][j]) % MOD
        dp[i][j] = m[i][j] + (max(dp[i-1][j], dp[i][j-1]))
        return dp[i][j]
    
def matrix_path(m, n):
    global cnt
    for i in range(n+1):
        d[i][0] = 0
    for j in range(1, n+1):
        d[0][j] = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            cnt += 1
            d[i][j] = m[i][j] + max(d[i-1][j], d[i][j-1])
    return d[n][n]

matrix_path_rec(m, n, n)
print(d[n][n], ((n%MOD)*(n%MOD))%MOD)