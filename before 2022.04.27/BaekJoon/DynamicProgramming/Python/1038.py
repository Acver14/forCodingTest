import sys
input = sys.stdin.readline

n = int(input())

dp = [-1] * (n+1)
if n <= 10:
    print(n)
    exit()
if n >= 1023:
    print(-1)
    exit()
for i in range(10):
    dp[i] = i

for i in range(10, n+1):
    val = str(dp[i-1] + 1)
    while dp[i] == -1:
        for s in range(1, len(val)):
            if val[s-1] <= val[s]:
                v = str(int(val[s-1]) + 1)
                l = list(val)
                l[s-1] = v
                for j in range(s, len(val)):
                    l[j] = '0'
                val = "".join(l)
                break
            if s == len(val)-1:
                dp[i] = int(val)
print(dp[n])

# 예쁜 코드...
# https://ryu-e.tistory.com/59