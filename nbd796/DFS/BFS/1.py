from collections import deque


n, m = map(int, input().split())
arr = [[0]*m for i in range(n)]
for i in range(n):
    # arr[i] = list(map(int, list(input())))
    arr[i] = list(map(int, input()))
visited = [[False]*m for i in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

ans = 0
flag = False
for i in range(n):
    for j in range(m):
        if visited[i][j] is False and arr[i][j]==0:
            q = deque([(i,j)])
            visited[i][j] = True
            flag = True
            while q:
                x, y = q.popleft()
                for k in range(4):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny] or arr[nx][ny]==1: continue
                    q.append((nx, ny))
                    visited[nx][ny] = True
            if flag:
                ans+=1
                flag = False
print(ans)

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False

    if arr[x][y] == 0:
        arr[x][y] = 1
        
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    return False
ans = 0

for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            ans += 1
print(ans)
