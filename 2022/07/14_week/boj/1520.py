import sys
sys.setrecursionlimit(100000)
M, N = map(int, input().split())
arr = []
visited = [[-1] * N for _ in range(M)]
for _ in range(M):
    arr.append(list(map(int, input().split())))

mv = [[1, 0], [-1, 0], [0, -1], [0, 1]]
def dfs(x, y):
    global arr, visited
    visited[x][y] = 0
    if x == M-1 and y == N-1:
        visited[x][y] = 1
        return 1
    for dx, dy in mv:
        nx, ny = x + dx, y + dy
        if 0 <= nx < M and 0 <= ny < N:
            if arr[nx][ny] < arr[x][y]:
                if visited[nx][ny] == -1:
                    visited[x][y] += dfs(nx, ny)
                else:
                    visited[x][y] += visited[nx][ny]
    return visited[x][y]
print(dfs(0, 0))