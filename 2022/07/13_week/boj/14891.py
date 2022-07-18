arr = []
for _ in range(4):
    arr.append(list(input()))
N = int(input())
order = []
for _ in range(N):
    order.append(list(map(int, input().split())))
    
def rotate(arr, dir):
    if dir == -1:
        return arr[1:] + [arr[0]]
    elif dir == 1:
        return [arr[-1]] + arr[:-1]
# 접합부 2, 6
for num, dir in order:
    num -= 1
    rdir = dir
    prev = arr[num][2]
    for i in range(num, 3):
        rdir *= -1
        if prev != arr[i+1][6]:
            prev = arr[i+1][2]
            arr[i+1] = rotate(arr[i+1], rdir)
            continue
        break
    ldir = dir
    prev = arr[num][6]
    for i in range(num, 0, -1):
        ldir *= -1
        if prev != arr[i-1][2]:
            prev = arr[i-1][6]
            arr[i-1] = rotate(arr[i-1], ldir)
            continue
        break
    
    arr[num] = rotate(arr[num], dir)
ans = 0
for i in range(4):
    if arr[i][0] == '1':
        ans += 2**i
print(ans)