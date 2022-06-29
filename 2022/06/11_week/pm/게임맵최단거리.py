def solution(maps):
    answer = 0
    n, m = len(maps), len(maps[0])
    dist = [[0]*m for _ in range(n)]
    d = [[-1, 0], [0, -1], [1, 0], [0, 1]]
    q = [(0, 0)]
    dist[0][0] = 1
    dist[n-1][m-1] = -1
    while q:
        x, y = q.pop(0)
        for i in d:
            nx, ny = x + i[0], y + i[1]
            if 0 <= nx < n and 0 <= ny < m:
                if maps[nx][ny] == 1 and dist[nx][ny] < 1:
                    q.append((nx, ny))
                    dist[nx][ny] = dist[x][y]+1
                    
    return dist[n-1][m-1]