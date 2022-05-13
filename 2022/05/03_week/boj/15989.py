import sys
input = sys.stdin.readline

t = int(input())
dp = [[0] * 4 for _ in range(10001)]
dp[1][1] = 1
dp[2][1] = 1
dp[2][2] = 1
dp[3][1] = 1
dp[3][2] = 1
dp[3][3] = 1
idx = 4
for _ in range(t):
    n = int(input())
    if idx > n:
        print(sum(dp[n]))
    else:
        for i in range(idx, n+1):
            # why? 수식이 오름차순으로 정렬되어 있으므로, 2로 끝나는 수열이라면 [i-2][3]값을 더해주지 않아야 오름차순이 지켜진다.
            dp[i][1] = dp[i-1][1]
            dp[i][2] = dp[i-2][1] + dp[i-2][2]
            dp[i][3] = sum(dp[i-3])
        print(sum(dp[n]))
        if idx < n: idx = n
       