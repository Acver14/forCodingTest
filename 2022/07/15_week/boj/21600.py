N = int(input())
arr = list(map(int, input().split()))
dp = [0 for _ in range(N)]

for i in range(1, N):
    if arr[i] > dp[i-1]:
        dp[i] = dp[i-1]+1
    else:
        dp[i] = arr[i]
print(max(dp))