import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

dx = [1, -1, 1, -1, 0, 0, 1, -1]
dy = [1, -1, -1, 1, 1, -1, 0, 0]

def bfs(sx, sy):
    q = deque()
    visited = [[False]*m for _ in range(n)]
    q.append((sx, sy, 0))
    visited[sx][sy] = True
    while q:
        x, y, cnt = q.popleft()
        if arr[x][y] == 1:
            return cnt
        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if visited[nx][ny]:
                continue
            visited[nx][ny] = True
            q.append((nx, ny, cnt+1))
            
ans = 0
for i in range(n):
    for j in range(m):
        if arr[i][j] != 1:
            ans = max(ans, bfs(i, j))
print(ans)