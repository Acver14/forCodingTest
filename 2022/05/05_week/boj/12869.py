import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

INF = 2100000000
dp = [[[INF] * (100) for _ in range(100)] for _ in range(100)]
dp[0][0][0] = 0

damage = []
if len(arr) == 3:
    damage = [[9, 3, 1], [9, 1, 3], [3, 1, 9], [1, 3, 9], [1, 9, 3], [3, 9, 1]]
elif len(arr) == 2:
    damage = [[9, 3, 0], [3, 9, 0]]
    arr += [0]
else:
    damage = [[9, 0, 0]]
    arr += [0, 0]

q = deque([[0, 0, 0]])
while q:
    x, y, z = q.popleft()
    if x == arr[0] and y == arr[1] and z == arr[2]:
        print(dp[x][y][z])
        break
    
    for i in range(len(damage)):
        dx, dy, dz = damage[i]
        
        nx, ny, nz = x+dx, y+dy, z+dz
        if x+dx >= arr[0]:
            nx = arr[0]
        if y+dy >= arr[1]:
            ny = arr[1]
        if z+dz >= arr[2]:
            nz = arr[2]
            
        if dp[nx][ny][nz] > dp[x][y][z]+1:
            dp[nx][ny][nz] = dp[x][y][z]+1
            q.append([nx, ny, nz])