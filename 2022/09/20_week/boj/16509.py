from collections import deque
mv = [
    [[1, 0], [1, 1], [1, 1]],
    [[1, 0], [1, -1], [1, -1]],
    [[0, 1], [1, 1], [1, 1]],
    [[0, 1], [-1, 1], [-1, 1]],
    [[-1, 0], [-1, -1], [-1, -1]],
    [[-1, 0], [-1, 1], [-1, 1]],
    [[0, -1], [1, -1], [1, -1]],
    [[0, -1], [-1, -1], [-1, -1]]
]
sx, sy = map(int, input().split())
kx, ky = map(int, input().split())
nx, ny = 10, 9
visited = [[0]*ny for _ in range(nx)]
q = deque([[sx, sy, 0]])
visited[sx][sy] = 1
ans = -1
while q:
    x, y, d = q.popleft()
    if x == kx and y == ky:
        ans = d
        break
    for i in range(8):
        tx, ty = x, y
        for j in range(3):
            tx, ty = tx + mv[i][j][0], ty + mv[i][j][1]
            if 0 <= tx < nx and 0 <= ty < ny:
                if tx == kx and ty == ky and j < 2:
                    break
                if j == 2 and not visited[tx][ty]:
                    q.append([tx, ty, d+1])
                    visited[tx][ty] = 1
print(ans)
                