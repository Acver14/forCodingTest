from collections import deque


n, m = map(int, input().split())

arr = [[0]*m for i in range(n)]
for i in range(n):
    # arr[i] = list(map(int, list(input())))
    arr[i] = list(map(int, input()))
dist = [[-1]*m for i in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

q = deque([(0,0)])
arr[0][0] = 0
dist[0][0] = 1
while q:
    x, y = q.popleft()
    if x==n-1 and y==m-1: break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= m or arr[nx][ny]==0: continue
        q.append((nx, ny))
        arr[nx][ny] = 0
        if dist[nx][ny] == -1 or dist[nx][ny] > dist[x][y]+1:
            dist[nx][ny] = dist[x][y]+1
                
print(dist[n-1][m-1])
