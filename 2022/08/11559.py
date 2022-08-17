from collections import deque

N, M = 12, 6
arr = []
for _ in range(N):
    arr.append(list(input()))

def drop():
    global arr
    for i in reversed(range(N-1)):
        for j in reversed(range(M)):
            if arr[i][j] != '.':
                l = i
                while l+1 < N and arr[l+1][j] == '.':
                    l += 1
                if l > i:
                    arr[l][j], arr[i][j] = arr[i][j], '.'
                
def puyo():
    global arr
    mv = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    ret = False
    for i in range(N):
        for j in range(M):
            if arr[i][j] != '.':
                color = arr[i][j]
                memo = [[i, j]]
                q = deque([[i, j]])
                while q:
                    x, y = q.popleft()
                    for dx, dy in mv:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < N and 0 <= ny < M:
                            if arr[nx][ny] == color and [nx, ny] not in memo:
                                memo.append([nx, ny])
                                q.append([nx, ny])
                if len(memo) >= 4:
                    for x, y in memo:
                        arr[x][y] = '.'
                    ret = True
    return ret

ans = 0
while True:
    if puyo():
        ans += 1
    else:
        print(ans)
        break
    drop()
    