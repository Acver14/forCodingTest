from sys import stdin
import heapq as h
input = stdin.readline

n = int(input().rstrip())
max_h = []
min_h = []
for i in range(n):
    num = int(input().rstrip())

    if len(min_h) == len(max_h):
        h.heappush(min_h, -num)
    else:
        h.heappush(max_h, num)

    if max_h and max_h[0] < -min_h[0]:
        leftValue = h.heappop(min_h)
        rightValue = h.heappop(max_h)

        h.heappush(min_h, -rightValue)
        h.heappush(max_h, -leftValue)

    print(-min_h[0])