import sys
import heapq
input = sys.stdin.readline
V, E = map(int, input().split())
K = int(input())
INF = 21000000
vec = [[] for _ in range(V + 1)]
for i in range(E):
    u, v, w = map(int, input().split())
    vec[u].append((w, v))
    
visited = [INF] * (V+1)
q = []
heapq.heappush(q,(0, K))
visited[K] = 0
while q:
    dw, node = heapq.heappop(q)
    if visited[node] < dw:
        continue
    for w, u in vec[node]:
        nw = dw + w
        if visited[u] > nw:
            heapq.heappush(q, (nw, u))
            visited[u] = nw
            
            
for v in range(1, V+1):
    if visited[v] == INF:
        print('INF')
        continue
    print(visited[v])