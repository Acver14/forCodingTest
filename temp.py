arr = []
for i in range(10):
        arr.append(list(map(int, input().split())))
        
x, y = 1, 1
arr[x][y] = 9
move = True
while move:
    if arr[x][y+1] != 1:
        y = y+1
        if arr[x][y] == 2: move = False
        arr[x][y] = 9
    elif arr[x+1][y] != 1:
        x = x+1
        if arr[x][y] == 2: move = False
        arr[x][y] = 9
    else: break

for i in range(10):
    for j in range(10):
        print(arr[i][j], end=' ')
    print()