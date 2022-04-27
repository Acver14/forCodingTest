import sys
from collections import deque
input = sys.stdin.readline

m, n = map(int, input().split())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(input())
    
visited = [[False] * m for _ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
def bfs(sx, sy):
    global visited, dx, dy
    if visited[sx][sy]:
        return 0
    else:
        ret = 0
        visited[sx][sy] = True
        color = arr[sx][sy]
        q = deque()
        q.append((sx, sy))
        while q:
            x, y = q.popleft()
            ret += 1
            for i in range(4):
                nx = x+dx[i]
                ny = y+dy[i]
                if nx < 0 or ny < 0 or nx >= n or ny >= m or arr[nx][ny] != color:
                    continue
                if not visited[nx][ny]:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        return ret
    
ans = {
    'W': 0,
    'B': 0
}
for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            ans[arr[i][j]] += bfs(i, j)**2
print(ans['W'], ans['B'])