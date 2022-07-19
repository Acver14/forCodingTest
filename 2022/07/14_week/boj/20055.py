N, K = map(int, input().split())
k = 0
arr = list(map(int, input().split()))
q = [0 for _ in range(2*N)]

cnt = 0
while True:
    # 1 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    q = [q[-1]] + q[:-1]
    arr = [arr[-1]] + arr[:-1]
    q[N-1] = 0
    # 2 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    #   로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
    for i in range(N-2, -1, -1):
        if q[i] and not q[i+1] and arr[i+1]:
            arr[i+1] -= 1
            q[i+1], q[i] = q[i], 0
            if arr[i+1] == 0:
                k += 1
    q[N-1] = 0
    # 3 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
    if arr[0] > 0:
        q[0] = 1
        arr[0] -= 1
        if arr[0] == 0:
            k += 1
    cnt += 1
    # 4 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다
    if k >= K:
        break
print(cnt)
    