from sys import stdin
from collections import defaultdict

input = stdin.readline

n = int(input().rstrip())
d = defaultdict(int)
for _ in range(n):
    d[input().rstrip()] += 1
for _ in range(n-1):
    d[input().rstrip()] -= 1

for key, value in d.items():
    if value > 0:
        print(key)