n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
check = [[0] * m for _ in range(n)]
boomerang = [[[1, 0], [0, 1]], [[1, 0], [0, -1]], [[-1, 0], [0, 1]], [[-1, 0], [0, -1]]]

ans = 0
def go(i, j, sum):
    global ans, n, m
    if j == m:
        i += 1
        j = 0
    if i == n:
        ans = max(ans, sum)
        return
    if check[i][j] == 0:
        for b in boomerang:
            temp = 0
            nx1, ny1 = i + b[0][0], j + b[0][1]
            nx2, ny2 = i + b[1][0], j + b[1][1]
            if 0 <= nx1 < n and 0 <= ny1 < m and check[nx1][ny1] == 0 and 0 <= nx2 < n and 0 <= ny2 < m and check[nx2][ny2] == 0:
                temp += arr[nx1][ny1]
                temp += arr[nx2][ny2]
            else:
                continue
            temp += arr[i][j] * 2
            check[nx1][ny1] = check[nx2][ny2] = check[i][j] = 1
            go(i, j+1, sum + temp)
            ans = max(ans, sum+temp)
            check[nx1][ny1] = check[nx2][ny2] = check[i][j] = 0
    go(i, j+1, sum)
go(0, 0, 0)
print(ans)
