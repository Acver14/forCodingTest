from sys import stdin
from collections import deque
input = stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    tree = [[] for _ in range(m+1)]
    for i in range(m):
        a, b = map(int, input().split())
    print(n-1)