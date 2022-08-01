N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

mv = [[], [0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1]]

cloud = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]
for _ in range(M):
    d, s = map(int, input().split())
    wasCloud = []
    while cloud:
        x, y = cloud.pop()
        nx, ny = (x + mv[d][0] * s) % N, (y + mv[d][1] * s) % N
        wasCloud.append((nx, ny))
        arr[nx][ny] += 1
        wcnt = 0
        for i in range(2, 9, 2):
            wx, wy = nx+mv[i][0], ny+mv[i][1]
            if 0 <= wx < N and 0 <= wy < N and arr[wx][wy] > 0:
                    wcnt += 1
        arr[nx][ny] += wcnt
    for i in range(N):
        for j in range(N):
            if arr[i][j] >= 2 and (i, j) not in wasCloud:
                cloud.append((i, j))
                arr[i][j] -= 2

print(sum(sum(a) for a in arr))