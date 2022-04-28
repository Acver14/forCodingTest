import sys
from collections import deque
input = sys.stdin.readline

n, m, k = map(int, input().split())

arr = [[0]*m for _ in range(n)]
starts = []
for _ in range(k):
    x, y = map(int, input().split())
    arr[x-1][y-1] = 1
    starts.append((x-1, y-1))
  
visited = [[False]*m for _ in range(n)]

def bfs(sx, sy):
    global visited
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    if visited[sx][sy]:
        return 0
    q = deque()
    q.append((sx, sy))
    visited[sx][sy] = True
    ret = 0
    while q:
        x, y = q.popleft()
        ret += 1
        for i in range(4):
            nx, ny = x + dx[i], y+dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m or arr[nx][ny] == 0 or visited[nx][ny]:
                continue
            else:
                visited[nx][ny] = True
                q.append((nx, ny))
    return ret

ans = 0
for x, y in starts:
    ans = max(ans, bfs(x, y))
print(ans)