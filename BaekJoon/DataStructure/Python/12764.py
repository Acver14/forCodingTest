# https://black-hair.tistory.com/101
import sys
import heapq
from collections import deque

START, END = 0, 1
N = int(sys.stdin.readline().strip())
time_set = [list(map(int, sys.stdin.readline().split()))for _ in range(N)]
time_set.sort(key=lambda x: (x[START], x[END]))
time_set = deque(time_set)
computers = []      #heap
empty = [i for i in range(N)]
heapq.heapify(empty)            #사용할 수 있는 컴퓨터
tick = -1
count = [0 for _ in range(N)]
answer = [0]            # 0번은 갯수 1번부터 사용한 횟수

while time_set:
    tick += 1
    if tick == time_set[0][START]:
        temp = time_set.popleft()
        idx = heapq.heappop(empty)
        heapq.heappush(computers, [temp[END], temp[START], idx])
        count[idx] += 1
    if computers and computers[0][0] == tick:
        s, e, i = heapq.heappop(computers)
        heapq.heappush(empty, i)

for i in count:
    if i == 0:
        break
    else:
        answer.append(i)
        answer[0] += 1

print(answer[0])
print(*answer[1:])