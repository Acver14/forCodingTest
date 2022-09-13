import sys
input = sys.stdin.readline
s1 = '_' + input().rstrip()
s2 = '_' + input().rstrip()

dp = [[0]*len(s2) for _ in range(len(s1))]
ans = 0
for i, val1 in enumerate(s1):
    for j, val2 in enumerate(s2):
        if i == 0 or j == 0:
            dp[i][j] = 0
        elif val1 == val2:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        ans = max(ans, dp[i][j])
print(ans)