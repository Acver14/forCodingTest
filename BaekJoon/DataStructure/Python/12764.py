from sys import stdin
import heapq as h
input = stdin.readline

n = int(input().rstrip())
heap = []
t = []
for _ in range(n):
    t.append(list(map(int, input().rstrip().split())))
    
t.sort(key=lambda x:(x[0], x[1]))

com = 0
seat = []
for i in t:
    min_seat = 100001
    while heap:
        print(heap, i)
        item = h.heappop(heap)
        if item[0] < i[0]:
            # h.heappush(heap, (i[1], i[0], item[2]))
            # seat[item[2]] += 1
            if min_seat > item[2]: min_seat = item[2]
        else:
            if min_seat == 100001:
                seat.append(1)
                h.heappush(heap, item)
                h.heappush(heap, (i[1], i[0], com))
                com += 1
            else:
                h.heappush(heap, (i[1], i[0], min_seat))
                print('hi',heap)
            break
    if not heap:
        h.heappush(heap, (i[1], i[0], com))
        seat.append(1)
        com += 1
        
print(com)
for i in seat:
    print(i, end=' ')