import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
g, s, d = 0, 1, 2
arr = [[0] for _ in range(n+1)]
for i in range(1, n+1):
    arr[i] += list(map(int, input().split()))

dp = [[[0]*(n+1) for _ in range(n+1)] for _ in range(3)]

dp[g][1][2] = 1
for i in range(1, n+1):
    for j in range(1, n+1):
        if i < 1 or j < 1 or i > n or j > n:
            continue
        if arr[i][j] == 0:
            if j-1 > 0 and arr[i][j-1] == 0:
                dp[g][i][j] += dp[g][i][j-1] + dp[d][i][j-1]
                # print(i, j, i, j-1)
            if i-1 > 0 and arr[i-1][j] == 0:
                dp[s][i][j] += dp[s][i-1][j] + dp[d][i-1][j]
                # print(i, j, i-1, j)
            if i-1 > 0 and j-1 > 0 and arr[i-1][j] == 0 and arr[i][j-1] == 0 and arr[i-1][j-1] == 0:
                dp[d][i][j] += dp[d][i-1][j-1] + dp[g][i-1][j-1] + dp[s][i-1][j-1]
print(dp[g][n][n] + dp[s][n][n] + dp[d][n][n])            
            




# q = deque()
# q.append(start)
# ans = 0
# while q:
#     y, x, dir = q.popleft()
#     if y == n and x == n:
#         ans += 1
#         continue
#     for i in move[dir]:
#         ny, nx = y + i[0], x + i[1]
#         stat = i[2]
#         if nx > n or ny > n:
#             continue
#         if arr[ny][nx] == 0:
#             if stat == d:
#                 if arr[ny-1][nx-1] == 0 and arr[ny-1][nx] == 0 and arr[ny][nx-1] == 0:
#                     q.append((ny, nx, stat))
#                     continue
#             elif stat == g:
#                 if arr[ny][nx-1] == 0:
#                     q.append((ny, nx, stat))
#                     continue
#             elif stat == s:
#                 if  arr[ny-1][nx] == 0:
#                     q.append((ny, nx, stat))
#                     continue
# print(ans)