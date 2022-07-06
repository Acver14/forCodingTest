def dfs(i, j, k, cnt, color):
    global arr, visited, d, N
    if 0 <= i < N and 0 <= j < N:
        if color != arr[i][j]:
            return cnt
        visited[k][i][j] = True
        return dfs(i+d[k][0], j+d[k][1], k, cnt+1, color)
    else:
        return cnt

N = 19
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
    
d = [[1, 0], [0, 1], [1, 1], [1, -1]]

visited = [[[False] * N for _ in range(N)] for _ in range(4)]

for i in range(N):
    for j in range(N):
        if arr[i][j] != 0:
            for k in range(4):
                if not visited[k][i][j]:
                    cnt = dfs(i, j, k, 0, arr[i][j])
                    if cnt == 5:
                        if k == 3:
                            print(arr[i+4][j-4])
                            print(i+5, j-3)
                        else:
                            print(arr[i][j])
                            print(i+1, j+1)
                        exit()
print(0)