import sys
from collections import deque
input = sys.stdin.readline

n, m, k = map(int, input().split())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(input().rstrip())
x1, y1, x2, y2 = map(int, input().split())
x1, y1, x2, y2 = x1-1, y1-1, x2-1, y2-1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque()
INF = 1000*1000
dist = [[INF]*m for _ in range(n)]
q.append((x1, y1))
dist[x1][y1] = 0
while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        nk = 1
        while 0 <= nx < n and 0 <= ny < m and arr[nx][ny] == '.' and nk <= k and dist[nx][ny] > dist[x][y]:
            if dist[nx][ny] == INF:
                q.append((nx, ny))
                dist[nx][ny] = dist[x][y] + 1
            nx += dx[i]
            ny += dy[i]
            nk += 1
   
if dist[x2][y2] == INF:
    print(-1)
else:
    print(dist[x2][y2])