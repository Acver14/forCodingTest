N = int(input())
arr = []

_min, _max = [[], [float('inf')]*3], [[], [0]*3]
_min[0] = list(map(int, input().split()))
_max[0] = _min[0].copy()
x = 0

for _ in range(N-1):
    arr = list(map(int, input().split()))
    _min[x-1][0] = min(_min[x][0] + arr[1], _min[x][0] + arr[2])
    _min[x-1][1] = min([_min[x][1] + arr[0], _min[x][1] + arr[1], _min[x][1] + arr[2]])
    _min[x-1][2] = min(_min[x][2] + arr[1], _min[x][2] + arr[2])
    
    _max[x-1][0] = max(_max[x][0] + arr[1], _max[x][0] + arr[2])
    _max[x-1][1] = max([_max[x][1] + arr[0], _max[x][1] + arr[1], _max[x][1] + arr[2]])
    _max[x-1][2] = max(_max[x][2] + arr[1], _max[x][2] + arr[2])
    
    _min[x] = [float('inf')]*3
    _max[x] = [0]*3
    x = (x+1)%2
    
print(max(_max[x]), min(_min[x]))