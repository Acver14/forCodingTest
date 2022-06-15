n = int(input())
arr = []
for _ in range(n-1):
    arr.append(list(map(int, input().split())))
if n == 1:
    arr.append(list(map(int, input().split())))
k = int(input())

INF = 21000000000
dp = [[INF] * (2) for _ in range(20)]

try:
    dp[0][0] = dp[1][0] = arr[0][0]
    dp[2][0] = min(dp[1][0] + arr[1][1], dp[1][0] + arr[1][0])
    dp[3][0] = min(dp[2][0] + arr[2][0], dp[1][0] + arr[2][1])
    dp[3][1] = k
except:
    None

for i in range(4, n):
    dp[i][0] = min(dp[i-1][0] + arr[i-1][0], dp[i-2][0] + arr[i-2][0])
    dp[i][1] = min(dp[i-1][1] + arr[i-1][0], dp[i-2][1] + arr[i-2][0], dp[i-3][0] + k)

print(min(dp[n-1]))