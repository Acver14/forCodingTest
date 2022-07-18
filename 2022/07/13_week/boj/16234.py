import sys
sys.setrecursionlimit(100000)
N, L, R = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
M = len(arr[0])
mv = [[0, 1], [1, 0], [0, -1], [-1, 0]]

def dfs(x, y, idx):
    global mv, N, M, visited
    for m in mv:
        nx, ny = x + m[0], y + m[1]
        if 0 <= nx < N and 0 <= ny < M:
            if L <= abs(arr[x][y] - arr[nx][ny]) <= R and visited[nx][ny] == -1:
                united.add((nx, ny))
                visited[nx][ny] = idx
                dfs(nx, ny, idx)

cnt = 0
while True:
    visited = [[-1 for _ in range(M)] for _ in range(N)]
    flag = False
    for i in range(N):
        for j in range(M):
            if visited[i][j] == -1:
                united = set()
                visited[i][j] = i*N+j
                dfs(i, j, visited[i][j])
                _sum = 0
                if not united:
                    continue
                else:
                    flag = True
                united.add((i, j))
                for uni in united:
                    _sum += arr[uni[0]][uni[1]]
                _sum //= len(united)
                for uni in united:
                    arr[uni[0]][uni[1]] = _sum
    if flag:
        cnt += 1
    else:
        break
print(cnt)