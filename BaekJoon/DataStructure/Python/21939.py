# from sys import stdin
# import heapq as h

# input = stdin.readline

# n = int(input().rstrip())
# hardq = []
# easyq = []
# idx = [0] * 100001
# for _ in range(n):
#     num, difficult = map(int, input().rstrip().split())
#     h.heappush(hardq, (-difficult, -num))
#     h.heappush(easyq, (difficult, num))
#     idx[num] = difficult

# m = int(input().rstrip())
# ans = ''
# for _ in range(m):
#     cmd = input().rstrip().split()
#     num = int(cmd[1])
#     if cmd[0] == 'recommend':
#         # ans += str(hardq) + '\n'
#         if num == 1:
#             ans += str(-hardq[0][1])+'\n'
#         elif num == -1:
#             ans += str(easyq[0][1])+'\n'
#     elif cmd[0] == 'add':
#         difficult = int(cmd[2])
#         h.heappush(hardq, (-difficult, -num))
#         h.heappush(easyq, (difficult, num))
#         idx[num] = difficult
#     elif cmd[0] == 'solved':
#         easyq.remove((idx[num], num))
#         hardq.remove((-idx[num], -num))
#         idx[num] = 0
# print(ans)

import sys
input = sys.stdin.readline
from heapq import heappop,heappush
from collections import defaultdict


N = int(input())
min_heap = []
max_heap = []
in_list = defaultdict(bool)
for _ in range(N):
    P, L = map(int, input().split())
    heappush(min_heap,[L,P])
    heappush(max_heap,[-L,-P])
    in_list[P] = True

M = int(input())
for _  in range(M):
    command = input().split()
    if command[0]=='recommend':
        if command[1]=='1':
            while not in_list[-max_heap[0][1]]:
                heappop(max_heap)
            print(-max_heap[0][1])
        else:
            while not in_list[min_heap[0][1]]:
                heappop(min_heap)
            print(min_heap[0][1])
    elif command[0]=='solved':
        in_list[int(command[1])] = False
    else:
        P = int(command[1])
        L = int(command[2])
        # 같은 번호의 다른 난이도 문제가 삽입되어 이미 죽은 문제인데 True로 나와 출력되는 것을 방지.
        while not in_list[-max_heap[0][1]]:
            heappop(max_heap)
        while not in_list[min_heap[0][1]]:
            heappop(min_heap)
        in_list[P] = True
        heappush(max_heap,[-L,-P])
        heappush(min_heap,[L,P])