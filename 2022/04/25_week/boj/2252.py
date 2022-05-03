import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

# DFS
n, m = map(int, input().split())

arr = [[] for _ in range(n+1)]
for _ in range(m):
    s, b = map(int, input().split())
    arr[b].append(s)

visited = [False] * (n+1)
def dfs(start):
    global visited, arr
    visited[start] = True
    for i in arr[start]:
        if not visited[i]:
            dfs(i)
    print(start, end=' ')

for i in range(1, n+1):
    if not visited[i]:
        dfs(i)
        
# Topology Sort
from collections import deque
n, m = map(int, input().split())

arr = [[] for _ in range(n+1)]
entry = [0] * (n+1)
for _ in range(m):
    s, b = map(int, input().split())
    entry[b] += 1
    arr[s].append(b)

q = deque()
for i in range(1, n+1):
    if entry[i] == 0:
        q.append(i)
while q:
    cur = q.popleft()
    print(cur)
    for i in range(len(arr[cur])):
        next = arr[cur][i]
        entry[next] -= 1
        
        if entry[next] == 0:
            q.append(next)