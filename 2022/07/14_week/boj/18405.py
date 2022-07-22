from sys import stdin
from collections import deque
input = stdin.readline

N, K = map(int, input().split())
arr = []
start = [(0, 0, 0) for _ in range(K+1)]
for i in range(N):
    arr.append(list(map(int, input().split())))
    
S, X, Y = map(int, input().split())
X -= 1
Y -= 1

mv = [[1, 0], [0, 1], [-1, 0], [0, -1]]
q = [deque() for _ in range(K+1)]

for i in range(N):
    for j in range(N):
        if arr[i][j] > 0:
            q[arr[i][j]].append((i, j, 0))
            
prev = 0
while q:
    x, y, s = 0, 0, -1
    for i in range(1, K+1):
        while q[i] and q[i][0][2] == prev:
            x, y, s = q[i].popleft()
            if (x == X and y == Y) or s == S:
                break
            for m in mv:
                nx, ny = x + m[0], y + m[1]
                if 0 <= nx < N and 0 <= ny < N:
                    if arr[nx][ny] == 0:
                        arr[nx][ny] = arr[x][y]
                        q[i].append((nx, ny, s+1))
    else:
        prev = s+1
    if s == -1:
        break
print(arr[X][Y])

