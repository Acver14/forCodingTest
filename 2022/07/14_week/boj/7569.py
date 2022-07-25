from collections import deque
M, N, H = map(int, input().split())
box = [[[] for _ in range(N)] for _ in range(H)]
q = deque()
for i in range(H):
    for j in range(N):
        box[i][j] = list(map(int, input().split()))
        for k in range(M):
            if box[i][j][k] == 1:
                q.append((i, j, k, 0))
    
mv = [[0, 0, 1], [0, 1, 0], [0, 0, -1], [0, -1, 0], [1, 0, 0], [-1, 0, 0]]

days = 0
while q:
    h, n, m, d = q.popleft()
    days = d
    for dx, dy, dz in mv:
        nh, nn, nm = h + dz, n + dy, m + dx
        if 0 <= nh < H and 0 <= nn < N and 0 <= nm < M:
            if box[nh][nn][nm] == 0:
                box[nh][nn][nm] = 1
                q.append((nh, nn, nm, d+1))

for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 0:
                print(-1)
                exit()
print(days)