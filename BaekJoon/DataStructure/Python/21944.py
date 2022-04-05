import sys
input = sys.stdin.readline
from heapq import heappop,heappush
from collections import defaultdict


N = int(input())
max_heap = defaultdict([])
min_heap = defaultdict([])
total_heap = []
in_list = defaultdict(bool)
for _ in range(N):
    P, L, G = map(int, input().split())
    heappush(min_heap[G],[L,P])
    heappush(max_heap[G], [-L,-P])
    heappush(total_heap, [L,P])
    in_list[P] = True

M = int(input())
for _  in range(M):
    command = input().split()
    if command[0]=='recommend':
        if command[2]=='1':
            G = int(command[1])
            while not in_list[-max_heap[G][0][1]]:
                heappop(max_heap[G])
            print(-max_heap[G][0][1])
        else:
            while not in_list[min_heap[G][0][1]]:
                heappop(min_heap[G])
            print(min_heap[G][0][1])
    elif command[0]=='recommend2':
        x = int(command[1])
        while not in_list[]
    elif command[0]=='solved':
        in_list[int(command[1])] = False
    else:
        P = int(command[1])
        L = int(command[2])
        G = int(command[3])
        # 같은 번호의 다른 난이도 문제가 삽입되어 이미 죽은 문제인데 True로 나와 출력되는 것을 방지.
        while not in_list[-max_heap[G][0][1]]:
            heappop(max_heap)
        while not in_list[min_heap[G][0][1]]:
            heappop(min_heap)
        in_list[P] = True
        heappush(max_heap[G],[-L,-P])
        heappush(min_heap[G],[L,P])