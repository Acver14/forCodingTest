from sys import stdin
import heapq as h

input = stdin.readline

t = int(input().rstrip())

for _ in range(t):
    n = int(input().rstrip())
    m = []
    if n % 10 == 0:
        for _ in range(n//10):
            m.extend(list(map(int, stdin.readline().rstrip().split(' '))))
    else:
        for _ in range(n//10+1):
            m.extend(list(map(int, stdin.readline().rstrip().split(' '))))

    max_arr = []
    min_arr = []
    mid = m[0]
    result = [mid]
    for i in range(1, len(m)):
        if m[i] > mid:
            h.heappush(max_arr, m[i])
        else:
            h.heappush(min_arr, -m[i])
            
        if i % 2 == 0:
            if len(min_arr) < len(max_arr):
                h.heappush(min_arr, -mid)
                mid = h.heappop(max_arr)
            elif len(min_arr) > len(max_arr):
                h.heappush(max_arr, mid)
                mid = -h.heappop(min_arr)
            result.append(mid)
            
    print(len(result))
    for i in range(len(result)):
        if i != 0 and (i+1) % 10 == 1:
            print()
        print(result[i], end=' ')