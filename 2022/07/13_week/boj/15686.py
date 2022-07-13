from itertools import combinations

n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))

chicken = []
house = []
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            house.append((i, j))
        elif arr[i][j] == 2:
            chicken.append((i, j))

combi = combinations(chicken, m)
ans = 2100000000
for c in combi:
    dist = 0
    for val in house:
        temp = 2100000000
        for chick in c:
            temp = min(temp, abs(chick[0]-val[0]) + abs(chick[1]-val[1]))
        dist += temp
    ans = min(ans, dist)
print(ans)