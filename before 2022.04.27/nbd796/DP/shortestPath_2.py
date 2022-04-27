import heapq
# 1 -> k -> x

def dijkstra(start):
    distance[start] = 0
    q = []
    heapq.heappush(q, (0, start))
    while q:
        dist, now = heapq.heappop(q)
        
        if distance[now] <dist:
            continue
        
        for i in v[now]:
            cost = dist + 1
            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(q, (cost, i))
    return distance[k] 

n, m = map(int, input().split())
INF = int(1e9)
v = [[] for _ in range(n+1)]

for i in range(m):
    x, y = map(int, input().split())
    v[x].append(y)
x, k = map(int, input().split())

distance = [INF] * (n+1)

start = dijkstra(1)
end = dijkstra(x)
print(start+end)


# case of Floid Warshel
INF = int(1e9)

n, m = map(int, input().split())

graph = [[INF] * (n+1) for _ in range(n+1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0
            
for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1
    
x, k = map(int, input().split())

for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
            
distance = graph[1][k] + graph[k][x]

if distance >= INF:
    print("-1")
else:
    print(distance)