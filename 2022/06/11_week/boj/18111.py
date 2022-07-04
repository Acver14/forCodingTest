from sys import stdin
input = stdin.readline

N, M, B = map(int, input().split())
arr = []
_min, _max = float('inf'), 0
for i in range(N):
    arr += (list(map(int, input().split())))
_min = min(arr)
_max = max(arr)
    

criteria = 0
time = float('inf')
height = 0
for h in range(_min, _max+1):
    if h * N * M > sum(arr) + B:
        break
    b = B
    t = 0
    for n in range(N*M):
        temp = h - arr[n]
        if arr[n] < h:
            b -= temp
            t += temp
        elif arr[n] > h:
            b -= temp
            t += temp * (-2)
    if b >= 0:
        if time >= t:
            time = t
            height = h
            
print(time, height)