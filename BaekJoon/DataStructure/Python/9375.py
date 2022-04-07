from sys import stdin
from collections import defaultdict
input = stdin.readline

t = int(input().rstrip())

for _ in range(t):
    wear = defaultdict(int)
    n = int(input().rstrip())
    for i in range(n):
        wear[input().rstrip().split()[1]] += 1
    ans = 1
    for i in wear.values():
        ans *= i+1
    print(ans - 1)