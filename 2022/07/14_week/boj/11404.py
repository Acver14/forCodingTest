import heapq as hq
N = int(input())
M = int(input())
INF = float('inf')

arr = [[INF]*(N+1) for _ in range(N+1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    if arr[u][v] > w:
        arr[u][v] = w
for i in range(1, N+1):
    arr[i][i] = 0
    
def floyd():
    global arr
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])

floyd()

for i in range(1, N+1):
    for j in range(1, N+1):
        if arr[i][j] == INF:
            print(0, end=' ')
        else:
            print(arr[i][j], end=' ')
    print()