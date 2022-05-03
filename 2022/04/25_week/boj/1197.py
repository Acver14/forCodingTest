# 출처 : https://deveun.tistory.com/entry/Python%EB%B0%B1%EC%A4%80-1197%EC%B5%9C%EC%86%8C-%EC%8A%A4%ED%8C%A8%EB%8B%9D-%ED%8A%B8%EB%A6%ACPrim-Kruskal
import sys
import heapq
input = sys.stdin.readline
sys.setrecursionlimit(1000000)

v, e = map(int, input().split())
edge = [[] for _ in range(v+1)]
arr = []
for _ in range(e):
    a, b, c = map(int, input().split())
    edge[a].append([b, c])
    edge[b].append([a, c])
    arr.append([c, a, b])

# kruskal
que, dist, cnt = [], 0, 0
vi = [False for _ in range(v+1)]
heapq.heappush(que, (0, 1)) # dist, start vertex 
while cnt < v:
    (d, v2) = heapq.heappop(que)
    if not vi[v2]:
        vi[v2] = True 
        dist += d 
        cnt += 1
        for e in edge[v2]: 
            if not vi[e[0]]: 
                heapq.heappush(que, [e[1], e[0]])
print(dist)

#prim
parent = [i for i in range(v+1)]
def find(x): 
    global parent 
    if parent[x] == x: 
        return x
    else: 
        return find(parent[x])
def union(x, y):
    pX, pY = find(x), find(y) 
    if pX > pY: 
        parent[pX] = pY 
    else: 
        parent[pY] = pX
        
arr.sort() # 모든 간선을 오름차순으로 정렬
result = 0 
for a in arr:
    if find(a[1]) == find(a[2]): # 사이클이 발생하는 경우
        continue 
    union(a[1], a[2])
    result += a[0] 
print(result)
