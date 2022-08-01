N = int(input())
arr = list(map(int, input().split()))
dp = [0, 0]
_max = 0
for i in range(1, N):
    idx = i % 2
    if arr[i] > dp[idx-1]:
        dp[idx] = dp[idx-1]+1
    else:
        dp[idx] = arr[i]
    _max = max(_max, dp[idx])
print(_max)