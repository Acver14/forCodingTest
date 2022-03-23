import heapq

n, m, c = map(int, input().split())
INF = int(1e9)
v = [[] for _ in range(n+1)]

for i in range(m):
    x, y, z = map(int, input().split())
    v[x].append([y, z])
    
distance = [INF] * (n+1)

distance[c] = 0
q = []
heapq.heappush(q, (0, c))
while q:
    dist, now = heapq.heappop(q)
    
    if distance[now] <dist:
        continue
    
    for i in v[now]:
        cost = dist + i[1]
        if cost < distance[i[0]]:
            distance[i[0]] = cost
            heapq.heappush(q, (cost, i[0]))
    
t = -1
cnt = 0
for i in distance:
    if i != INF and i != 0:
        cnt += 1
        t = max(t, i)
print(cnt, t)