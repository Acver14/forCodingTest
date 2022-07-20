N = int(input())
friends = [0] * (N**2+1)
seated = [(0, 0)] * (N**2+1)
priority = []
cntEmpty = [[4]*(N+1) for _ in range(N+1)]
seat = [[-1]*(N+1) for _ in range(N+1)]

for i in range(2, N):
    cntEmpty[i][1], cntEmpty[i][N] = 3, 3
    cntEmpty[1][i], cntEmpty[N][i] = 3, 3
cntEmpty[1][1], cntEmpty[1][N], cntEmpty[N][1], cntEmpty[N][N] = 2, 2, 2, 2
cntEmpty[0][0] = -1
for i in range(N**2):
    temp = list(map(int, input().split()))
    priority.append(temp[0])
    friends[temp[0]] = temp[1:]
    
dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
# 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
# 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
# 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
def refreshEmptyCnt(x, y):
    global cntEmpty, dir
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        if 1 <= nx <= N and 1 <= ny <= N:
            cntEmpty[nx][ny] -= 1

def findFirst(n):
    global seated, friends, seat, dir
    friendList = [[], [], [], [], []]
    
    for friend in friends[n]:
        fx, fy = seated[friend]
        if fx == 0 and fy == 0:
            continue
        for dx, dy in dir:
            nx, ny = fx + dx, fy + dy
            if 1 <= nx <= N and 1 <= ny <= N:
                if seat[nx][ny] == -1:
                    fcnt = 0
                    for ddx, ddy in dir:
                        nnx, nny = nx + ddx, ny + ddy
                        if 1 <= nnx <= N and 1 <= nny <= N:
                            if seat[nnx][nny] in friends[n]:
                                fcnt += 1
                    friendList[fcnt].append((nx,ny))
    for i in range(4, -1, -1):
        if friendList[i]:
            return friendList[i]
    maxEmpty = (0, 0)
    for i in range(1, N+1):
        for j in range(1, N+1):
            if seat[i][j] == -1:
                if cntEmpty[i][j] > cntEmpty[maxEmpty[0]][maxEmpty[1]]:
                    maxEmpty = (i, j)
    return [maxEmpty]

for pri in priority:
    # 1
    first = findFirst(pri)
    if len(first) == 1 and first[0][0] != 0:
        x, y = first[0]
        seated[pri] = (x, y)
        refreshEmptyCnt(x, y)
        seat[x][y] = pri
        continue
    # 2
    second = []
    emptyList = [[],[],[],[],[]]
    for x, y in first:
        emptyList[cntEmpty[x][y]].append((x, y))
    for i in range(4, -1, -1):
        if emptyList[i]:
            second = emptyList[i].copy()
            break
    if len(second) == 1:
        x, y = second[0]
        seated[pri] = (x, y)
        refreshEmptyCnt(x, y)
        seat[x][y] = pri
        continue
    # 3
    third = sorted(second, key=lambda x:x[1])
    third = sorted(third, key=lambda x:x[0])
    x, y = third[0]
    seated[pri] = (x, y)
    refreshEmptyCnt(x, y)
    seat[x][y] = pri

ans = 0
for i in range(1, N**2+1):
    x, y = seated[i]
    cnt = 0
    for friend in friends[i]:
        nx, ny = seated[friend]
        if abs(x-nx) + abs(y-ny) == 1:
            cnt += 1
    if cnt:
        ans += 10**(cnt-1)
print(ans)