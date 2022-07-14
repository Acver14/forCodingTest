N, M = map(int, input().split())
r, c, d = map(int, input().split())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))
cleaned = [[False]*M for _ in range(N)]
cleaned[r][c] = True
ans = 1
# 1. 현재 위치를 청소한다.
# 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
#   1 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
#   2 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
#   3 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
#   4 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
# d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
mv = [[-1, 0], [0, 1], [1, 0], [0, -1]]
x, y, dir = r, c, d
while True:
    cnt = 0
    for m in mv:
        nx, ny = x + m[0], y + m[1]
        if (nx < 0 or nx >= N or ny < 0 or ny >= M) or cleaned[nx][ny] or arr[nx][ny]:
            cnt += 1
    if cnt == 4:
        nx, ny = x + mv[(dir+2)%4][0], y + mv[(dir+2)%4][1]
        if 0 <= nx < N and 0 <= ny < M and not arr[nx][ny]:
            if not cleaned[nx][ny]:
                cleaned[nx][ny] = True
                ans += 1
            x, y = nx, ny
            continue
        break
    nx, ny = x + mv[dir-1][0], y + mv[dir-1][1]
    if 0 <= nx < N and 0 <= ny < M:
        if not cleaned[nx][ny] and not arr[nx][ny]:
            dir -= 1
            if dir == -1:
                dir = 3
            x, y = nx, ny
            ans += 1
            cleaned[nx][ny] = True
            continue
        else:
            dir -= 1
            if dir == -1:
                dir = 3
            continue
print(ans)