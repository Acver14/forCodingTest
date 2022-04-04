import heapq
from sys import stdin
input = stdin.readline

heap = []
n = int(input().rstrip())
for _ in range(n):
    x = int(input().rstrip())
    if x == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (-x, x))
        # print(heap)
