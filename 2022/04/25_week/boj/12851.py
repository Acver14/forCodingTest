import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())

visited = [1e10] * 100001
q = deque()
q.append(n)
visited[n] = 0
ans, cnt = 1e11, 1
while q:
    node = q.popleft()
    dist = visited[node]
    if node == k:
        if ans > dist:
            ans = dist
            cnt = 1
        elif ans == dist:
            cnt += 1
        continue
            
    nnode = node+1
    if nnode < 100001 and visited[nnode] >= dist+1:
        q.append(nnode)
        visited[nnode] = dist+1
    nnode = node-1
    if nnode > -1 and visited[nnode] >= dist+1:
        q.append(nnode)
        visited[nnode] = dist+1
    nnode = node*2
    if nnode < 100001 and nnode > -1 and visited[nnode] >= dist+1:
        q.append(nnode)
        visited[nnode] = dist+1
        
print(ans)
print(cnt)