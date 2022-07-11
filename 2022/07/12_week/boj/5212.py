def checkOcean(x, y):
    global arr, r, c
    cnt = 0
    dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    for d in dir:
        nx, ny = x + d[0], y + d[1]
        if 0 <= nx < r and 0 <= ny < c:
            if arr[nx][ny] == '.':
                cnt += 1
        else:
            cnt += 1
    return cnt > 2

r, c = map(int, input().split())
arr = []
for i in range(r):
    arr.append(list(input()))
    
minX, minY, maxX, maxY = r, c, 0, 0
    
for i in range(r):
    for j in range(c):
        if arr[i][j] == 'X':
            if checkOcean(i, j):
                arr[i][j] = 'Y'
            else:
                if minX > i:
                    minX = i
                if minY > j:
                    minY = j
                if maxX < i:
                    maxX = i
                if maxY < j:
                    maxY = j
ans = []
for i in range(minX, maxX+1):
    ans.append([])
    for j in range(minY, maxY+1):
        if arr[i][j] == 'Y':
            ans[i-minX].append('.')
        else:
            ans[i-minX].append(arr[i][j])
for i in ans:
    print(''.join(i))

