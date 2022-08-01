N, M = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
comm = []
for _ in range(M):
    comm.append(tuple(map(int, input().split())))
mv = [[], [0, -1], [1, -1], [1, 0], [1, 1], [0, 1],[-1, 1], [-1, 0], [-1, -1]]
# ←, ↖, ↑, ↗, →, ↘, ↓, ↙
# 모든 구름이 di 방향으로 si칸 이동한다.
# 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
# 구름이 모두 사라진다.
# 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 
# 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
# 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
# 예를 들어, (N, 2)에서 인접한 대각선 칸은 (N-1, 1), (N-1, 3)이고, (N, N)에서 인접한 대각선 칸은 (N-1, N-1)뿐이다.
# 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
cloud = [(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)]

def move(cloud, d, s):
    new_cloud = []
    while cloud:
        x, y = cloud.pop()
        nx, ny = (x + mv[d][0] * s) % N, (y + mv[d][1] * s) % N
        new_cloud.append((nx, ny))
    return new_cloud

def copy(new_cloud):
    F = [(-1,-1),(1,1),(-1,1),(1,-1)]
    for x, y in new_cloud:
        wcnt = 0
        for f in F:
            wx, wy = x+f[0], y+f[1]
            if 0 <= wx < N and 0 <= wy < N:
                if arr[wx][wy] > 0:
                    wcnt += 1
        arr[x][y] += wcnt
        
for d, s in comm:
    new_cloud = move(cloud, d, s)
    for x, y in new_cloud:
        arr[x][y] += 1
    cloud = []
    copy(new_cloud)
    for i in range(N):
        for j in range(N):
            if arr[i][j] >= 2 and (i, j) not in new_cloud:
                cloud.append((i, j))
                arr[i][j] -= 2
           
print(sum(sum(a) for a in arr))