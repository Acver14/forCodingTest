def secondMax(arr):
    arr.sort()
    return arr[2]

n = int(input())
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

temp = []
while len(arr) > 1:
    for i in range(0, len(arr), 2):
        temp.append([])
        for j in range(0, len(arr[i]), 2):
            val = secondMax(arr[i][j:j+2] + arr[i+1][j:j+2])
            temp[i//2].append(val)
    arr = temp.copy()
    temp = []
print(arr[0][0])