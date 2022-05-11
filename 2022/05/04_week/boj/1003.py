import sys
input = sys.stdin.readline

ans = [[0,0] for _ in range(41)]
ans[0][0] = 1
ans[1][1] = 1

t = int(input())
idx = 2
for _ in range(t):
    n = int(input())
    for i in range(idx, n+1):
        ans[i][0] = ans[i-1][0] + ans[i-2][0]
        ans[i][1] = ans[i-1][1] + ans[i-2][1]
    if n > idx:
        idx = n
    print(ans[n][0], ans[n][1])