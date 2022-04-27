import sys
from collections import deque
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n, r, q = map(int, input().split())
tree = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)
    
starts = []
for _ in range(q):
    starts.append(int(input()))
    
cnt = [0] * (n+1)
def countEdge(edge, par):
    global tree, cnt
    c = len(tree[edge])
    if par != 0:
        c -= 1
    for i in tree[edge]:
        if i == par:
            continue
        c += countEdge(i, edge)
    cnt[edge] = c
    return c
countEdge(r, 0)

for i in starts:
    print(cnt[i]+1)
            