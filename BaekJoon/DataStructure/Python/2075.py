from sys import stdin
input = stdin.readline
import heapq

n = int(input().rstrip())
arr = []
for i in range(n):
    temp = list(map(int, input().rstrip().split()))
    for t in temp:
        heapq.heappush(arr, t)
        if len(arr)>n:
            heapq.heappop(arr)
            
print(heapq.heappop(arr))