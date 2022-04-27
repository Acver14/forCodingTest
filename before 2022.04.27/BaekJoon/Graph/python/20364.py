from sys import stdin
from collections import defaultdict, deque
input = stdin.readline

n, q = map(int, input().split())
land = []
for _ in range(q):
    land.append(int(input()))

share = defaultdict(bool)

for i in land:
    mink = -1
    k = i
    while True:
        if share[k]:
            mink = k
        if k == 0:
            if mink > -1:
                print(mink)
            else:
                print(0)
                share[i] = True
            break
        k //= 2
        
