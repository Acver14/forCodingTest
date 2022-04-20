# python으로 문제 해결시 시간초과 발생 -> pypy3로 언어 변경 후 풀이 시 문제 해결
from sys import stdin
from collections import deque
input = stdin.readline

n = int(input())
a = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, input().split())
    a[u].append(v)
    a[v].append(u)
    
q = deque()
q.append((1, 0))
v = [False] * (n+1)
v[1] = True
ans = 0
while q:
    node, c = q.popleft()
    if len(a[node]) == 1:
        ans += c
    for i in range(len(a[node])):
        next = a[node][i]
        if not v[next]:
            flag = True
            v[next] = True
            q.append((next, c+1))

if ans%2:
    print('Yes')
else:
    print('No')