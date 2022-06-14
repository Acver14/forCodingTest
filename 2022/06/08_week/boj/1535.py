n = int(input())
hp = list(map(int, input().split()))
pleasure = list(map(int, input().split()))

dp = [[0 for _ in range(101)] for _ in range(n+1)]

for i in range(n):
    for j in range(101):
        if j - hp[i] > 0:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-hp[i]] + pleasure[i])
        else:
            dp[i][j] = dp[i-1][j]
            
print(max(dp[n-1]))