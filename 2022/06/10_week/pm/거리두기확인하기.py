def dfs(x, y, arr, cnt):
    if 0 < cnt <= 2:
        if arr[x][y] == 'P':
            return 0
    if cnt == 2:
        return 1
    arr[x][y] = 'X'
    d = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    for i in range(4):
        nx, ny = x + d[i][0], y + d[i][1]
        if 0 <= nx < 5 and 0 <= ny < 5:
            if arr[nx][ny] == 'P': 
                ret = dfs(nx, ny, arr, cnt+1)
                arr[nx][ny] = 'P'
                if ret == 0:
                    return 0
            if arr[nx][ny] == 'O':
                ret = dfs(nx, ny, arr, cnt+1)
                arr[nx][ny] = 'O'
                if ret == 0:
                    return 0
    return 1
    
def func(arr):
    ans = 1
    for i in range(5):
        for j in range(5):
            if arr[i][j] == 'P':
                if dfs(i, j, arr, 0) == 0:
                    return 0
    return 1

def solution(places):
    answer = []
    for p in range(len(places)):
        arr = []
        for i in range(len(places[p])):
            arr.append(list(places[p][i]))
        ar = arr.copy()
        answer.append(func(arr))
            
        
    return answer