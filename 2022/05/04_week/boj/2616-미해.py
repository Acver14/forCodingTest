import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
m = int(input())

S = [0]
value = 0
for t in arr:
    value += t
    S.append(value)
    
dp = [[0]*(n+1) for _ in range(4)]

for i in range(1, 4):
    for j in range(i*m, n+1):
        if n == 1:
            dp[i][j] = max(dp[i][j - 1], S[j] - S[j - m])

        # 점화식
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + S[j] - S[j - m])