from sys import stdin
import heapq as h
input = stdin.readline

heap = []
n = int(input().rstrip())
for _ in range(n):
    x = int(input().rstrip())
    if x == 0:
        if heap: print(h.heappop(heap))
        else: print(0)
    else:
        h.heappush(heap, x)