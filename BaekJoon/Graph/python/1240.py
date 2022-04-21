from dis import dis
import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
tree = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v, d = map(int, input().split())
    tree[u].append((v, d))
    tree[v].append((u, d))

visited = [False] * (n+1)
distance = [[0] * (n+1) for _ in range(n+1)]

def dfs(start, i, d):
    global distance, visited
    distance[start][i] = d
    for j in range(len(tree[i])):
        toi = tree[i][j][0]
        cost = tree[i][j][1]
        if not visited[toi]:
            visited[toi] = True
            dfs(start, toi, d+cost)
            visited[toi] = False
            
for i in range(1, n+1):
    visited[i] = True
    dfs(i, i, 0)
    visited[i] = False
print(distance)
for _ in range(m):
    a, b = map(int, input().split())
    print(distance[a][b])
