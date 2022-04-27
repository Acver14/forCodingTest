from sys import stdin
from collections import deque
input = stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    tree = [[] for _ in range(n+1)]
    for _ in range(n-1):
        p, c = map(int, input().split())
        tree[c].append(p)
    find_list = list(map(int, input().split()))
    chase = [deque(), deque()]
    for f in range(len(find_list)):
        q = deque()
        q.append(find_list[f])
        visited = [False for _ in range(n+1)]
        visited[find_list[f]] = True
        while q:
            node = q.popleft()
            chase[f].append(node)
            for i in tree[node]:
                if not visited[i]:
                    visited[i] = True
                    q.append(i)
    while chase[0]:
        c = chase[0].popleft()
        for i in chase[1]:
            if i == c:
                print(i)
                chase[0] = []
                break