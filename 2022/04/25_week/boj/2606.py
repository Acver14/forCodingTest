import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
e = int(input())
arr = [[] for _ in range(n+1)]
for _ in range(e):
    u, v = map(int, input().split())
    arr[u].append(v)
    arr[v].append(u)
    
visited = [False] * (n+1)
q = deque()
q.append(1)
visited[1] = True
ans = -1
while q:
    node = q.popleft()
    ans += 1
    for i in range(len(arr[node])):
        nnode = arr[node][i]
        if not visited[nnode]:
            q.append(nnode)
            visited[nnode] = True
print(ans)
