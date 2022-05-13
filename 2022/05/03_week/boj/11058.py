import sys
input = sys.stdin.readline

n = int(input())

dp = [0] * (n + 1)

if n <= 6:
    print(n)
    exit(0)

for i in range(1, 7):
    dp[i] = i

for i in range(7, n + 1):
    for j in range(3, i):
        dp[i] = max((j - 1) * dp[i - j], dp[i])

print(dp[n])