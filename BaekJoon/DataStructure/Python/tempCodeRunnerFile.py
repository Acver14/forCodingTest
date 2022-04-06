from sys import stdin
from collections import defaultdict

input = stdin.readline

n = int(input().rstrip())
d = defaultdict(int)
a = []
for _ in range(n):
    a.append(input().rstrip())
for _ in range(n-1):
    d[input().rstrip()] = 1
for i in a:
    if d[i] == 0:
        print(i)
        break