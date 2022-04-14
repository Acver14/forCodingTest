from sys import stdin
from collections import deque
input = stdin.readline

n, w = map(int, input().split())
tree = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)
 
ans = 0
for i in range(2, len(tree)):
    if len(tree[i]) <= 1:
        ans += 1
        
print(w/ans)