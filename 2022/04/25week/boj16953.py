import sys
from collections import deque
input = sys.stdin.readline

a, b = map(int, input().split())

q = deque()
q.append((a,0))
INF = 1e10
ans = INF
while q:
    node, cnt = q.popleft()
    if node == b:
        ans = min(ans, cnt)
    # case 1
    nnode = node * 10 + 1
    if nnode <= b:
        q.append((nnode, cnt+1))
    # case 2
    nnode = node * 2
    if nnode <= b:
        q.append((nnode, cnt+1))
        
if ans == INF:
    print(-1)
else:
    print(ans+1)
    