import math

dp = [1 for _ in range(1000001)]

for i in range(1, 1000001):
    a = math.floor(i-i**(1/2))
    b = math.floor(math.log(i))
    c = math.floor(i * math.sin(i)**2)
    dp[i] = ((dp[a] + dp[b]) % 1000000 + dp[c]) % 1000000

while True:
    n = int(input())
    if n == -1:
        break
    print(dp[n])